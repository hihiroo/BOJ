//LCA2
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int par[100005][30], lv[100005];
vector<vector<int> > v(100005);

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(lv[next] == -1){
            lv[next] = lv[vtx]+1;
            par[next][0] = vtx;
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    cin >> n;

    for(int i=1; i<n; i++){
        int s,f;
        scanf("%d%d",&s,&f);
        v[s].pb(f), v[f].pb(s);
    }

    memset(lv,-1,sizeof(lv));
    lv[1] = 0, dfs(1);

    for(int i=1; i<=25; i++)
        for(int j=1; j<=n; j++)
            par[j][i] = par[par[j][i-1]][i-1];

    cin >> m;
    while(m--){
        int a, b, gap;
        scanf("%d%d",&a,&b);
        if(lv[a] < lv[b]) swap(a,b);

        gap = lv[a] - lv[b];
        for(int i=0; (1<<i)<=gap; i++)
            if((1<<i) & gap) a = par[a][i];

        if(a != b){
            for(int k=25; k>=0; k--){
                if(par[a][k] != par[b][k]){
                    a = par[a][k];
                    b = par[b][k];
                }
            }
            a = par[a][0];
        }
        cout << a << '\n';
    }
}
