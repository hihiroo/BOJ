//책 구매하기3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int f[205][205], c[205][205], cost[205][205];
vector<vector<int> > v(205);

pair<int,int> flow(int s, int e){
    int ans = 0, ans2 = 0;
    while(1){
        vector<int> par(205,-1), dist(205,1e8);
        vector<bool> InQ(205,0);
        queue<int> q;

        q.push(s), InQ[s] = 1;
        par[s] = s, dist[s] = 0;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            InQ[vtx] = 0;

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(c[vtx][next] > f[vtx][next] && dist[next] > dist[vtx] + cost[vtx][next]){
                    dist[next] = dist[vtx] + cost[vtx][next];
                    par[next] = vtx;
                    if(!InQ[next]){
                        InQ[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        if(par[e] == -1) break;

        int poss = 1e8;
        for(int i=e; i!=s; i=par[i])
            poss = min(poss,c[par[i]][i]-f[par[i]][i]);

        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
            ans2 += poss*cost[par[i]][i];
        }

        ans += poss;
    }
    return mp(ans,ans2);
}



int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        scanf("%d",&c[0][i]);
        v[0].pb(i), v[i].pb(0);
    }

    for(int i=n+1; i<=n+m; i++){
        scanf("%d",&c[i][n+m+1]);
        v[i].pb(n+m+1), v[n+m+1].pb(i);
    }

    for(int i=n+1; i<=n+m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&c[j][i]);
            v[j].pb(i), v[i].pb(j);
        }
    }

    for(int i=n+1; i<=n+m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&cost[j][i]);
            cost[i][j] = -cost[j][i];
        }
    }

    pair<int,int> ans = flow(0,n+m+1);
    cout<<ans.fst<<"\n"<<ans.snd;
}
