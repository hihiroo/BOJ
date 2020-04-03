//내리갈굼
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int galgum[100005];
vector<vector<int> > v(100005);

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        galgum[next] += galgum[vtx];
        dfs(next);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int r;
        scanf("%d",&r);

        if(r == -1) continue;
        v[r].pb(i);
    }

    for(int i=0; i<m; i++){
        int k, a;
        scanf("%d%d",&k,&a);
        galgum[k] += a;
    }

    dfs(1);

    for(int i=1; i<=n; i++)
        printf("%d ",galgum[i]);
}