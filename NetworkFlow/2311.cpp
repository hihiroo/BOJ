//왕복 여행
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int c[1005][1005], f[1005][1005], d[1005][1005];
vector<vector<int> > v(1005);

int flow(int s, int e){
    int ans = 0, cnt = 0;
    while(1){
        vector<int> par(1005,-1), dist(1005,1e9);
        vector<bool> inQ(1005);
        queue<int> q;
        q.push(s), inQ[s] = 1, dist[s] = 0;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            inQ[vtx] = 0;

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                int cost = d[vtx][next];
                if(f[vtx][next] == -1) cost *= -1;

                if(c[vtx][next] > f[vtx][next] && dist[next] > dist[vtx] + cost){
                    dist[next] = dist[vtx] + cost;
                    par[next] = vtx;
                    if(!inQ[next]){
                        inQ[next] = 1;
                        q.push(next);
                    }
                }
            }
        }

        for(int i=e; i!=s; i=par[i]){
            if(f[par[i]][i] == -1) ans -= d[par[i]][i];
            else ans += d[par[i]][i];
            f[par[i]][i]++;
            f[i][par[i]]--;
        }
        cnt++;
        if(cnt == 2) return ans;
    }
}

int main(){
    cinFast();
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        v[a].pb(b), v[b].pb(a);
        d[a][b] = cost, d[b][a] = cost;
        c[a][b] = 1, c[b][a] = 1;
    }

    cout << flow(1,n);
}
