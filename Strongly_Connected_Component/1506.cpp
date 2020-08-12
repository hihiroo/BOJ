//경찰서
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int visit[105], cnt, ans, cost[105], n, arr[105][105];
bool scc[105];
stack<int> s;

int dfs(int vtx){
    visit[vtx] = ++cnt;
    s.push(vtx);

    int par = visit[vtx];
    for(int i=1; i<=n; i++){
        if(!arr[vtx][i]) continue;
        if(!visit[i]) par = min(par,dfs(i));
        else if(!scc[i]) par = min(par,visit[i]);
    }

    if(par == visit[vtx]){
        int good = 1e9;
        while(1){
            int comp = s.top();
            s.pop();
            good = min(good,cost[comp]);
            scc[comp] = 1;
            if(comp == vtx) break;
        }
        ans += good;
    }
    return par;
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> cost[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%1d",&arr[i][j]);

    for(int i=1; i<=n; i++)
        if(!visit[i]) dfs(i);

    cout << ans;
}
