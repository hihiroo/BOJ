//웜홀
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(505);

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        int dist[505], visit[505];
        fill(dist,dist+505,1e8);
        fill(visit,visit+505,0);
        for(int i=0; i<505; i++) v[i].clear();

        int n, m, w, s, e, time;
        cin>>n>>m>>w;
        for(; m>0; m--){
            scanf("%d%d%d",&s,&e,&time);
            v[s].pb(mp(e,time));
            v[e].pb(mp(s,time));
        }
        for(; w>0; w--){
            scanf("%d%d%d",&s,&e,&time);
            v[s].pb(mp(e,-time));
        }

        bool poss = false;
        for(int i=1; i<=n; i++){
            if(visit[i]) continue;
            visit[i] = 1, dist[i] = 0;
            for(int x = 0; x < n; x++){
                for(int j=1; j<=n; j++){
                    for(int k=0; k<v[j].size(); k++){
                        int next = v[j][k].fst;
                        int cost = v[j][k].snd;
                        if(dist[j] != 1e8 && dist[next] > dist[j] + cost){
                            dist[next] = dist[j] + cost;
                            visit[next] = 1;
                            if(x == n-1){
                                poss = true;
                                break;
                            }
                            
                        }
                    }
                }
            }
        }
        if(poss) printf("YES\n");
        else printf("NO\n");
    }
}

