// 해킹

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(10005);
bool visit[10005];

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        int n,d,c;
        cin>>n>>d>>c;
        for(int i=0; i<=n; i++) v[i].clear();
        
        for(int i=0; i<d; i++){
            int a,b,s;
            scanf("%d%d%d",&a,&b,&s);
            v[b].pb(mp(a,s));
        }

        memset(visit,0,sizeof(visit));
        priority_queue<pair<int,int> > q;
        q.push(mp(0,c));
        int ans = 0, last;

        while(!q.empty()){
            int cost = -q.top().fst;
            int vtx = q.top().snd;
            q.pop();

            if(visit[vtx]) continue;
            visit[vtx] = 1;
            ans++;
            last = cost;

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i].fst;
                if(!visit[next])
                    q.push(mp(-cost-v[vtx][i].snd,next));
            }
        }
        printf("%d %d\n",ans,last);
    }
}