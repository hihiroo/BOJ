// 한동이는 영업사원!
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define fst first
#define mp make_pair
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(100005);
int depth[100005], par[100005][21];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(depth[next]) continue;

        depth[next] = depth[vtx] + 1;
        par[next][0] = vtx;
        dfs(next);
    }
}

int main(){
    cinFast();
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    depth[1] = 1;
    dfs(1);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            int mid = par[j][i-1];
            par[j][i] = par[mid][i-1];
        }
    }

    int m, ans = 0;
    cin >> m;

    int pre = 1;
    while(m--){
        int a = pre, b;
        cin >> pre;
        b = pre;

        if(depth[a] < depth[b]) swap(a,b);
        int gap = depth[a] - depth[b];

        for(int i=0; i<20 && (1<<i) <= gap; i++){
            if(gap & (1<<i)){
                ans += (1<<i);
                a = par[a][i];
            }
        }

        if(a != b){
            for(int i=19; i>=0; i--){
                if(par[a][i] != par[b][i]){
                    a = par[a][i];
                    b = par[b][i];
                    ans += 2*(1<<i);
                }
            }
            ans += 2;
        }
    }
    cout << ans;
}
