//LCA
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<vector<int> > v(50005);
int par[50005][30], depth[50005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!par[next][0]){
            par[next][0] = vtx;
            depth[next] = depth[vtx]+1;
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    cin >> n;

    int a, b;
    for(int i=1; i<n; i++){
        scanf("%d%d",&a,&b);
        v[a].pb(b), v[b].pb(a);
    }

    par[1][0] = 1;
    dfs(1);

    for(int i=1; i<30; i++)
        for(int j=1; j<=n; j++)
            par[j][i] = par[par[j][i-1]][i-1];

    cin >> m;
    while(m--){
        scanf("%d%d",&a,&b);
        if(depth[a] < depth[b]) swap(a,b);

        int gap = depth[a]-depth[b];
        for(int i=0; i<30; i++)
            if(gap & (1<<i)) a = par[a][i];

        if(a != b){
            for(int i=29; i>=0; i--){
                if(par[a][i] != par[b][i]){
                    a = par[a][i];
                    b = par[b][i];
                }
            }
            printf("%d\n",par[a][0]);
        }
        else printf("%d\n",a);
    }
}
