//간선 이어가기2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(5005);

bool visit[5005];

int main(){
    int n,m;
    cin>>n>>m;

    int a,b,c;
    for(; m>0; m--){
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }

    int s,t;
    cin>>s>>t;

    priority_queue<pair<int,int> > q;
    q.push(mp(0,s));

    while(!q.empty()){
        int vtx = q.top().snd;
        int cost = -q.top().fst;
        q.pop();

        if(visit[vtx]) continue;
        visit[vtx] = true;
        if(vtx == t) return cout<<cost,0;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int cc = v[vtx][i].snd;
            if(!visit[next])
                q.push(mp(-cost-cc,next));
        }
    }
}
