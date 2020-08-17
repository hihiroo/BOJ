//리유나는 세일러복을 좋아해
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int f[405][405], c[405][405];
double wT[205], wK[205];
vector<vector<int> > v(405);

bool good(double wt, double wk){
    return (wt*0.5 <= wk && wk <= wt*0.75) || (wt <= wk && wk <= wt*1.25);
}

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(405,-1);
        queue<int> q;
        q.push(s);

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

        int poss = 1e9;
        for(int i=e; i!=s; i=par[i]){
            poss = min(poss,c[par[i]][i]-f[par[i]][i]);
        }

        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }
        ans += poss;
    }
    return ans;
}


int main(){
    cinFast();
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> wT[i];
        v[0].pb(i), v[i].pb(0);
        c[0][i] = 1;
    }
    for(int i=1; i<=m; i++){
        cin >> wK[i];
        v[n+i].pb(n+m+1), v[n+m+1].pb(n+i);
        c[n+i][n+m+1] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(good(wT[i],wK[j])){
                v[i].pb(n+j), v[n+j].pb(i);
                c[i][n+j] = 1;
            }
        }
    }
    cout << flow(0,n+m+1);
}
