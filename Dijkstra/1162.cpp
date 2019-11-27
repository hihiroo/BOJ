//도로포장

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long

lli visit[10005][25], n, m, k;
vector<vector<pair<lli,lli> > > v(10005);

int main(){
    memset(visit,-1,sizeof(visit));

    cin>>n>>m>>k;
    for(lli i=0; i<m; i++){
        lli s,e,cost;
        scanf("%lld%lld%lld",&s,&e,&cost);
        v[s].pb(mp(e,cost));
        v[e].pb(mp(s,cost));
    }
    
    priority_queue<pair<lli,pair<lli,lli> > > q;
    q.push(mp(0,mp(1,0)));

    while(!q.empty()){
        lli cost = -q.top().fst;
        lli vtx = q.top().snd.fst;
        lli cnt_k = q.top().snd.snd;
        q.pop();

        if(visit[vtx][cnt_k] != -1) continue;
        visit[vtx][cnt_k] = cost;

        if(vtx == n) return !printf("%lld",cost);

        for(lli i=0; i<v[vtx].size(); i++){
            lli next = v[vtx][i].fst;
            lli t = v[vtx][i].snd;

            if(visit[next][cnt_k] == -1)
                q.push(mp(-cost-t,mp(next,cnt_k)));
            if(cnt_k < k && visit[next][cnt_k+1] == -1)
                q.push(mp(-cost,mp(next,cnt_k+1)));
        } 
    }
}