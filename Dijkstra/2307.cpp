//도로검문
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(1005);
int par[1005], ban[1005][1005];

int dijkstra(int s, int e){
    memset(par,0,sizeof(par));
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(mp(0,mp(s,s)));

    while(!pq.empty()){
        int vtx = pq.top().snd.fst;
        int cost = -pq.top().fst;
        int pre = pq.top().snd.snd;
        pq.pop();

        if(par[vtx]) continue;
        par[vtx] = pre;
        if(vtx == e) return cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int next_cost = cost+v[vtx][i].snd;
            if(!par[next] && !ban[vtx][next]) pq.push(mp(-next_cost,mp(next,vtx)));
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        v[a].pb(mp(b,t));
        v[b].pb(mp(a,t));
    }

    int original = dijkstra(1,n);

    queue<pair<int,int> > path;
    for(int i=n; i!=1; i=par[i]) path.push(mp(i,par[i]));

    int ans = 0;
    while(!path.empty()){
        int s = path.front().fst;
        int e = path.front().snd;
        path.pop();

        ban[s][e] = 1, ban[e][s] = 1;

        int res = dijkstra(1,n);
        if(res == -1) return cout<<-1,0;
        ans = max(ans, res-original);

        ban[s][e] = 0, ban[e][s] = 0;
    }

    cout<<ans;
}
