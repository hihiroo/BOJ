#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
#define pii pair<int,int>
using namespace std;

namespace HuShing{
    int n;
    vector<lli> w, cp;

    struct HArc{
        int u, v;
        int low; // fan의 센터를 정할 때 필요
        lli base_cost;

        HArc(int u, int v): u(u), v(v){
            low = w[u] < w[v] ? u : v;
            base_cost = cp[v] - cp[u];
        };

        bool contain(HArc &a){
            return u <= a.u && v >= a.v;
        }
    };
    vector<HArc> h;
    vector<vector<int> > child; // 트리 구조 상의 자식노드

    /*Function*/
    vector<pii> one_sweep(){
        vector<int> stk; // 스택
        vector<pii> arcs;

        for(int i=0; i<n; i++){
            while(stk.size() >= 2 && w[stk.back()] > w[i]){
                //w[i]보다 작으면 fan이 더 이득이므로 넣지 않는다
                arcs.pb(mp(stk[stk.size()-2],i));
                stk.pop_back();
            }
            stk.pb(i);
        }
        while(stk.size() >= 3){
            arcs.pb(mp(0,stk[stk.size()-2]));
            stk.pop_back();
        }
        return arcs;
    }

    void build_tree(){
        vector<pii> arc;
        arc = one_sweep();

        stack<int> stk;
        h.pb(HArc(0,n)); // h0는 v0로 이루어진 degenerated arc

        for(int i=0; i<arc.size(); i++){
            int u = arc[i].fst, v = arc[i].snd;
            if(u == 0 || v == 0) continue; //h-arc만 분리 위해 v0와 연결된 arc제거

            h.pb(HArc(u,v));
            while(!stk.empty() && h.back().contain(h[stk.top()])){
                child[h.size()-1].pb(stk.top());
                stk.pop();
            }
            stk.push(h.size()-1);
        }

        while(!stk.empty()){
            child[0].pb(stk.top());
            stk.pop();
        }
    }
    
    lli get_ans(){
    
    }
    
    void construct(){
        /* 값이 가장 작은 v0를 찾고 맨 앞으로 오도록 rotate 시킴
        원형을 만들기 위해 마지막에 v0를 붙여 연결
        */
        rotate(w.begin(),min_element(w.begin(),w.end()),w.end());
        w.pb(w[0]);

        // cp[i] = w0:wi = w0w1 + w1w2 + ... + w(i-1)wi
        for(int i=1; i<=n; i++){
            cp[i] = cp[i-1] + w[i]*w[i-1];
        }

        build_tree();
    }

    void init(vector<lli>& v){
        w = v;
        n = v.size();
        cp.resize(n+1), h.reserve(n), child.resize(n);
    }

    lli solve(vector<lli> v){
        init(v);
        if(n < 2) return 0;
        if(n == 2) return w[0]*w[1];

        construct();
        return get_ans();
    }
};

int main(){
    vector<lli> v;
    v.pb(1), v.pb(2), v.pb(3), v.pb(4), v.pb(5), v.pb(4), v.pb(3), v.pb(4), v.pb(5), v.pb(4),v.pb(3),v.pb(2);
    cout << HuShing::solve(v);
}
