#include <bits/stdc++.h>
using namespace std;

#define pb push_back

long long c[405][405], f[405][405];
vector<vector<int> > v(405);

void flow(int s, int e){
    while(1){
        vector<int> par(405,-1);
        queue<int> q;
        
        q.push(s);
        par[s] = s;

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
        
        long long poss = 1e18;
        for(int i=e; i!=s; i=par[i]){
            poss = min(poss, c[par[i]][i]-f[par[i]][i]);
        }

        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    for(int i=1; i<=n; i++){
        cin >> c[i][n+i];
        v[i].pb(n+i);
        v[n+i].pb(i);
    }
    v[e+n].pb(2*n+1);
    v[2*n+1].pb(e+n);
    c[e+n][2*n+1] = 1e11;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        v[n+a].pb(b); // a' -> b
        v[b].pb(n+a);
        v[n+b].pb(a); // b' -> a
        v[a].pb(n+b);
        c[n+a][b] = 1e17;
        c[n+b][a] = 1e17;
    }
    flow(s,2*n+1);

    vector<bool> chk(405);
    queue<int> q;
    q.push(s);
    chk[s] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();
        
        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(chk[next] == false && c[vtx][next] > f[vtx][next]){
                chk[next] = true;
                q.push(next);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(chk[i] && !chk[i+n]){
           cout << i << " ";
        }
    }
}