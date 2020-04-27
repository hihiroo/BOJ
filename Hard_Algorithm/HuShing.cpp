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
        int low; // min(w[u],w[v])
        lli bm, bj; // S(hj/hk)의 분모, 분자
        lli base; // monotone polygon 에서 S 분모
        lli uv;

        HArc(int u, int v): u(u), v(v){
            low = w[u] <= w[v] ? u : v;
            base = cp[v] - cp[u] - w[u]*w[v];
            bm = base;
            uv = w[u]*w[v];
        };

        bool contain(HArc &a){
            return u <= a.u && v >= a.v;
        }

        lli get_S(){
            return bj/bm;
        }
    };

    vector<HArc> h;
    vector<vector<int> > child; // 트리 구조 상의 자식노드
    vector<vector<int> > connect;
    vector<vector<int> > ceiling;

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

    lli exclude_cp(int num){
        if(num == 0) return w[0]*w[1] + w[0]*w[n-1];

        HArc &a = h[num];
        if(a.low == a.u){
            if(connect[a.u].empty() || !a.contain(h[connect[a.u].back()]))
                return w[a.u]*w[a.u+1];
            else return h[connect[a.u].back()].uv;
        }
        else{
            if(connect[a.v].empty() || !a.contain(h[connect[a.v].back()]))
                return w[a.v]*w[a.v-1];
            else return h[connect[a.v].back()].uv;
        }
    }

    lli fan_cost(int vtx){
        HArc &a = h[vtx];
        return w[a.low]*(a.bm + a.uv - exclude_cp(vtx));
    }

    void add_arc(int vtx){
        connect[h[vtx].u].pb(vtx);
        connect[h[vtx].v].pb(vtx);
    }

    void remove_arc(int vtx){
        connect[h[vtx].u].pop_back();
        connect[h[vtx].v].pop_back();
    }

    void dfs(int vtx){
        priority_queue<pair<lli,int> > pq;

        for(int i=0; i<child[vtx].size(); i++){
            int next = child[vtx][i];
            dfs(next);

            h[vtx].bm -= h[next].base;
            pq.push(mp(h[next].get_S(), next));
        }

        while(!pq.empty() && pq.top().fst >= w[h[vtx].low]){
            // negative 한 경우 delete
            int idx = pq.top().snd;
            pq.pop();

            h[vtx].bm += h[idx].bm;
            remove_arc(idx);

            for(int i=0; i<ceiling[idx].size(); i++){
                int next = ceiling[idx][i];
                pq.push(mp(h[next].get_S(),next));
            }
        }
        h[vtx].bj = fan_cost(vtx);

        while(!pq.empty()){
            lli S = pq.top().fst;
            int idx = pq.top().snd;
            pq.pop();

            if(h[vtx].get_S() <= S){
                // idx가 vtx의 son
                h[vtx].bm += h[idx].bm;
                remove_arc(idx);
                h[vtx].bj += h[idx].bj;

                for(int i=0; i<ceiling[idx].size(); i++){
                    int next = ceiling[idx][i];
                    pq.push(mp(h[next].get_S(),next));
                }
            }
            else ceiling[vtx].pb(idx);
        }
        add_arc(vtx);
    }

    lli get_ans(int vtx){
        lli sum = h[vtx].bj;
        for(int i=0; i<ceiling[vtx].size(); i++){
            int next = ceiling[vtx][i];
            sum += get_ans(next);
        }
        return sum;
    }

    void construct(){
        /* 값이 가장 작은 v0를 찾고 맨 앞으로 오도록 rotate 시킴
        원형을 만들기 위해 마지막에 v0를 붙여 연결 */
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
        cp.resize(n+1), h.reserve(n);
        child.resize(n),connect.resize(n+1);

        ceiling.resize(n);
    }

    lli solve(vector<lli> v){
        init(v);
        if(n < 2) return 0;
        if(n == 2) return w[0]*w[1];

        construct();
        dfs(0);
        return get_ans(0);
    }
};

int main(){
    vector<lli> v;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v.pb(a);
        if(i == n-1) v.pb(b);
    }
    cout << HuShing::solve(v);
}
