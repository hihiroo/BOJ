//인터넷 설치
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<pair<int,int> > > v(1005);
int visit[1005][1005];

int main(){
    cinFast();

    int n,p,k;
    cin >> n >> p >> k;

    for(int i=0; i<p; i++){
        int a,b,c;
        cin >> a >> b >> c;

        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }

    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(mp(0,mp(0,1)));

    int ans = 1e9;
    while(!pq.empty()){
        int cost = -pq.top().fst;
        int free = pq.top().snd.fst;
        int vtx = pq.top().snd.snd;
        pq.pop();

        if(visit[vtx][free]) continue;
        visit[vtx][free] = 1;

        if(vtx == n){
            ans = min(ans,cost);
            return cout << ans,0;
        }

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int ncost = max(cost,v[vtx][i].snd);

            if(!visit[next][free]) pq.push(mp(-ncost,mp(free,next)));
            if(!visit[next][free+1] && free < k && cost < v[vtx][i].snd)
                pq.push(mp(-cost,mp(free+1,next)));
        }
    }

    cout << -1,0;
}
