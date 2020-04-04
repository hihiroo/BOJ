//트리와쿼리2
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<vector<pair<int,lli> > > v(100005);

int depth[100005];
pair<int,lli> par[100005][20];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;
        if(!par[next][0].fst){
            par[next][0].fst = vtx;
            par[next][0].snd = v[vtx][i].snd;
            depth[next] = depth[vtx] + 1;
            dfs(next);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int s,f;
        lli cost;
        scanf("%d%d%lld",&s,&f,&cost);
        v[s].pb(mp(f,cost)), v[f].pb(mp(s,cost));
    }

    par[1][0].fst = 1; dfs(1);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            pair<int,lli> tmp = par[j][i-1];
            par[j][i].fst = par[tmp.fst][i-1].fst;
            par[j][i].snd = par[j][i-1].snd + par[tmp.fst][i-1].snd;
        }
    }

    int m;
    cin >> m;
    while(m--){
        int q,u,v,k;
        scanf("%d%d%d",&q,&u,&v);
        if(q == 2) scanf("%d",&k);

        int a = u, b = v;
        if(depth[a] < depth[b]) swap(a,b);
        int gap = depth[a]-depth[b];

        lli cost = 0;
        for(int i=0; (1<<i)<=gap; i++){
            if((1<<i) & gap){
                cost += par[a][i].snd;
                a = par[a][i].fst;
            }
        }

        if(a != b){
            for(int i=19; i>=0; i--){
                if(par[a][i].fst != par[b][i].fst){
                    cost += par[a][i].snd+par[b][i].snd;
                    a = par[a][i].fst, b = par[b][i].fst;
                }
            }
            cost += par[a][0].snd + par[b][0].snd;
            a = par[a][0].fst, b = par[b][0].fst;
        }

        if(q == 1) printf("%lld\n",cost);
        else{
            k--;
            int l = depth[u] - depth[a];
            if(k > l){
                k = depth[v]-depth[a]-(k-l);
                u = v;
            }

            for(int i=0; (1<<i)<=k; i++){
                if((1<<i) & k) u = par[u][i].fst;
            }

            printf("%d\n",u);
        }
    }
}
