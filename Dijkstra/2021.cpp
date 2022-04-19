// 최소 환승 경로
#include <bits/stdc++.h>
using namespace std;
#define lli unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
    cinFast();
    int n, l;
    cin >> n >> l;

    vector<vector<pair<int,int> > > v(1200000);
    int cnt = n+1;
    for(int i=0; i<l; i++){
        int k, pre = -1;
        while(1){
            cin >> k;
            if(k == -1) break;

            v[k].pb({cnt,0});
            v[cnt].pb({k,1});

            if(pre != -1){
                v[cnt].pb({pre,0});
                v[pre].pb({cnt,0});
            }
            pre = cnt++;
        }
    }

    int s, e;
    cin >> s >> e;

    vector<int> chk(12000000,-1);
    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,s));

    while(!pq.empty()){
        int cost = -pq.top().fst;
        int vtx = pq.top().snd;
        pq.pop();

        if(chk[vtx] != -1) continue;
        if(vtx == e) return cout << max(cost-1,0),0;
        chk[vtx] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int total = cost + v[vtx][i].snd;

            if(chk[next] == -1) pq.push({-total,next});
        }
    }
    cout << -1;
}
