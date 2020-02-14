//책 구매하기2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > v(205);
int c[205][205], f[205][205];

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(205,-1);
        queue<int> q;
        q.push(s), par[s] = s;

        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(par[next] == -1 && c[vtx][next] > f[vtx][next]){
                    par[next] = vtx;
                    q.push(next);
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
        }
        ans += poss;
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
        scanf("%d",&c[i+n][n+m+1]);
        v[i+n].pb(n+m+1), v[n+m+1].pb(i+n);
    }
    for(int i=1; i<=m; i++){//서점
        for(int j=1; j<=n; j++){
            scanf("%d",&c[j][n+i]);
            v[j].pb(n+i), v[n+i].pb(j);
        }
    }
    cout<<flow(0,n+m+1);
}

