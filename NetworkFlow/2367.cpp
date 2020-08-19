//파티
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int c[305][305], f[305][305];
vector<vector<int> > v(305);

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(305,-1);
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
    int n,k,d;
    cin >> n >> k >> d;

    for(int i=1; i<=d; i++){//싱크와 음식 연결
        cin >> c[n+i][n+d+1];
        v[n+i].pb(n+d+1), v[n+d+1].pb(n+i);
    }

    for(int i=1; i<=n; i++){
        v[0].pb(i), v[i].pb(0);
        c[0][i] = k; //소스와 사람 연결

        int can, a;
        cin >> can;
        while(can--){
            cin >> a;
            v[i].pb(n+a), v[n+a].pb(i);
            c[i][n+a] = 1;
        }
    }

    cout << flow(0,n+d+1);
}

