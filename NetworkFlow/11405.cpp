//책 구매하기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > v(205);
int c[205][205], f[205][205], cost[205][205];

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(205,-1), dist(205,1e7);
        vector<bool> InQ(205,0);
        queue<int> q;
        par[s] = s;
        q.push(s), InQ[s] = true, dist[s] = 0;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();
            InQ[vtx] = false;

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(c[vtx][next]>f[vtx][next] && dist[next] > dist[vtx]+cost[vtx][next]){
                    par[next] = vtx;
                    dist[next] = dist[vtx] + cost[vtx][next];
                    if(!InQ[next]){
                        InQ[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        if(par[e] == -1) break;
        int poss = 1e7;
        for(int i=e; i!=s; i=par[i])
            poss = min(poss,c[par[i]][i]-f[par[i]][i]);

        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
            ans += cost[par[i]][i]*poss;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        scanf("%d",&c[0][i]);
        v[0].pb(i), v[i].pb(0);
    }
    for(int i=1; i<=m; i++){
        scanf("%d",&c[n+i][n+m+1]);
        v[n+i].pb(n+m+1), v[n+m+1].pb(n+i);
    }
    for(int i=1; i<=m; i++){//서점
        for(int j=1; j<=n; j++){//사람
            scanf("%d",&cost[j][i+n]);
            cost[i+n][j] = -cost[j][i+n];
            c[j][i+n] = c[0][j];
            v[j].pb(i+n), v[i+n].pb(j);
        }
    }
    cout<<flow(0,n+m+1);
}
