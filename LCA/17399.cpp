#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v(100005);
int par[100005][30], depth[100005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(depth[next] == -1){
            depth[next] = depth[vtx] + 1;
            par[next][0] = vtx;
            dfs(next);
        }
    }
}

void constructTable(int n){
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    dfs(1);

    for(int i=1; i<30; i++){
        for(int j=1; j<=n; j++){
            par[j][i] = par[par[j][i-1]][i-1]; 
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int gap = depth[a] - depth[b];

    for(int i=0; (1<<i)<=gap; i++){
        if(gap & (1<<i)) a = par[a][i];
    }

    if(a == b) return a;
    for(int i=29; i>=0; i--){
        if(par[a][i] == par[b][i]) continue;
        a = par[a][i];
        b = par[b][i];
    }
    return par[a][0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    constructTable(n);
    
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;

        int lcaAB = lca(a,b), lcaBC = lca(b,c), lcaAC = lca(a,c);
        int distAB = depth[a] - depth[lcaAB] + depth[b] - depth[lcaAB];
        int distBC = depth[b] - depth[lcaBC] + depth[c] - depth[lcaBC];
        int distAC = depth[a] - depth[lcaAC] + depth[c] - depth[lcaAC];

        int ans = -1;
        if(distAB % 2 ==0 && distAB >= distBC && distAB >= distAC){ // AB의 중점
            int dist = distAB/2, center = a;
            if(depth[b] > depth[a]) center = b;

            for(int i=0; (1<<i)<=dist; i++)
                if(dist & (1<<i)) center = par[center][i];

            int lcaCCe = lca(c,center);
            int distCCe = depth[c] - depth[lcaCCe] + depth[center] - depth[lcaCCe];
            if(distCCe == dist) ans = center;
        }
        if(distBC % 2 == 0 && distBC >= distAB && distBC >= distAC){ // BC의 중점
            int dist = distBC/2, center = c;
            if(depth[b] > depth[c]) center = b;

            for(int i=0; (1<<i)<=dist; i++)
                if(dist & (1<<i)) center = par[center][i];

            int lcaACe = lca(a,center);
            int distACe = depth[a] - depth[lcaACe] + depth[center] - depth[lcaACe];
            if(distACe == dist) ans = center;
        }
        if(distAC % 2 == 0 && distAC >= distAB && distAC >= distBC){ // AC의 중점
            int dist = distAC/2, center = a;
            if(depth[c] > depth[a]) center = c;

            for(int i=0; (1<<i)<=dist; i++)
                if(dist & (1<<i)) center = par[center][i];

            int lcaBCe = lca(b,center);
            int distBCe = depth[b] - depth[lcaBCe] + depth[center] - depth[lcaBCe];
            if(distBCe == dist) ans = center;
        }
        cout << ans << '\n';
    }
}