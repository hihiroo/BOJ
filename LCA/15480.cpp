//LCA와 쿼리
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair
#define pii pair<int,int>

vector<vector<int> > v(100005);
int par[100005][20], depth[100005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!par[next][0]){
            depth[next] = depth[vtx] + 1;
            par[next][0] = vtx;
            dfs(next);
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);

    int gap = depth[a] - depth[b];
    for(int i=0; i<20; i++)
        if(gap & (1<<i)) a = par[a][i];

    if(a == b) return a;
    for(int i=19; i>=0; i--){
        if(par[a][i] == par[b][i]) continue;
        a = par[a][i], b = par[b][i];
    }
    return par[a][0];
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].pb(b), v[b].pb(a);
    }

    par[1][0] = 1;
    dfs(1);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            int u = par[j][i-1];
            par[j][i] = par[u][i-1];
        }
    }

    int m;
    cin >> m;
    while(m--){
        int r,u,v;
        scanf("%d%d%d",&r,&u,&v);

        int ori = lca(u,v), ans;

        if(lca(ori,r) != ori) ans = ori;
        else{
            int x = lca(r,u), y = lca(r,v);

            if(x == ori) ans = y;
            else if(y == ori) ans = x;
            else if(x == r || y == r) ans = r;
            else if(x == u && y == v){
                if(ori == u) ans = v;
                else ans = u;
            }
        }
        printf("%d\n",ans);
    }
}
