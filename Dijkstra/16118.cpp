//달빛 여우
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

lli fox[4005], wolf[4005][2];

vector<vector<pair<int,lli> > > v(4005);

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int s,f;
        lli cost;
        scanf("%d%d%lld",&s,&f,&cost);
        v[s].pb(mp(f,cost*2));
        v[f].pb(mp(s,cost*2));
    }

    priority_queue<pair<lli,int> > pq;
    pq.push(mp(0,1));

    while(!pq.empty()){
        lli cost = -pq.top().fst;
        int vtx = pq.top().snd;
        pq.pop();

        if(fox[vtx]) continue;
        fox[vtx] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            if(!fox[next]) pq.push(mp(-cost-v[vtx][i].snd,next));
        }
    }

    priority_queue<pair<lli,pair<int,bool> > >  q;
    q.push(mp(0,mp(1,1)));

    while(!q.empty()){
        lli cost = -q.top().fst;
        int vtx = q.top().snd.fst;
        bool odd = q.top().snd.snd;
        q.pop();

        if(wolf[vtx][odd]) continue;
        wolf[vtx][odd] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            if(!wolf[next][!odd]){
                if(odd) q.push(mp(-cost-v[vtx][i].snd/2,mp(next,!odd)));
                else q.push(mp(-cost-v[vtx][i].snd*2,mp(next,!odd)));
            }
        }
    }

    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(!fox[i]) continue;
        if(!wolf[i][0]) wolf[i][0] = 1e10;
        if(!wolf[i][1]) wolf[i][1] = 1e10;
        if(fox[i] < min(wolf[i][0],wolf[i][1])) cnt++;
    }

    cout << cnt;
}
