//간선 끊어가기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(5005);

vector<int> dijkstra(int s, int e){
    vector<int> visit(5005,-1);

    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,s));
    while(!pq.empty()){
        int vtx = pq.top().snd;
        int cost = -pq.top().fst;
        pq.pop();

        if(visit[vtx] != -1) continue;
        visit[vtx] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int next_cost = cost + v[vtx][i].snd;
            if(visit[next] == -1) pq.push(mp(-next_cost,next));
        }
    }
    return visit;
}

int main(){
    int n,m,sum=0;
    cin>>n>>m;

    for(; m>0; m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
        sum += c;
    }

    int s,t;
    cin>>s>>t;

    vector<int> st, ts;
    st = dijkstra(s,t), ts = dijkstra(t,s);

    int ans = 1e8;
    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            int vtx = v[i][j].fst;
            ans = min(ans,st[i]+ts[vtx]);
        }
    }
    cout<<sum-ans;
}
