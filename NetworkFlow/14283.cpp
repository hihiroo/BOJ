//간선 이어가기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(55);

int f[55][55], c[55][55];

int flow(int s, int e){
    int ans = 0;

    while(1){
        vector<int> par(55,-1);
        queue<int> q;
        q.push(s), par[s] = s;

        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i].fst;
                if(par[next] == -1 && c[vtx][next] > f[vtx][next]){
                    par[next] = vtx;
                    q.push(next);
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
        }
        ans += poss;
    }
    return ans;
}

int main(){
    int n,m,sum=0;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,cost;
        scanf("%d%d%d",&a,&b,&cost);
        sum += cost;
        v[a].pb(mp(b,cost)), v[b].pb(mp(a,cost));
        c[a][b] += cost, c[b][a] += cost;
    }

    int s,t, ori, ans = 0;
    cin>>s>>t;

    ori = flow(s,t);

    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            memset(f,0,sizeof(f));
            int e = v[i][j].fst, cost = v[i][j].snd;
            c[i][e] -= cost, c[e][i] -= cost;
            if(ori-cost == flow(s,t)) ans = max(ans,cost);
            c[i][e] += cost, c[e][i] += cost;
        }
    }
    cout<< sum - ori + ans;
}
