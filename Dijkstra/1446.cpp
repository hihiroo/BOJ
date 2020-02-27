//지름길
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

bool visit[20005];
vector<vector<pair<int,int> > > v(10005);

int main(){
    int n,d;
    cin>>n>>d;

    int a,b,c;
    for(int i=0; i<n; i++){
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
    }

    priority_queue<pair<int,int> > q;
    q.push(mp(0,0));

    while(!q.empty()){
        int vtx = q.top().snd;
        int dist = -q.top().fst;
        q.pop();

        if(vtx > d || visit[vtx]) continue;
        visit[vtx] = true;
        if(vtx == d) return cout<<dist,0;

        if(!visit[vtx+1]) q.push(mp(-dist-1,vtx+1));
        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int cost = v[vtx][i].snd;

            if(!visit[next]) q.push(mp(-dist-cost,next));
        }
    }
}
