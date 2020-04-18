//순열 사이클
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

bool visit[1005];
vector<vector<int> > v(1005);

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visit[next]){
            visit[next] = 1;
            dfs(next);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        memset(visit,0,sizeof(visit));
        for(int i=1; i<=n; i++) v[i].clear();

        for(int i=1; i<=n; i++){
            int a;
            scanf("%d",&a);
            v[a].pb(i), v[i].pb(a);
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(visit[i]) continue;
            dfs(i);
            if(visit[i] == 1) ans++;
        }

        cout << ans << '\n';
    }
}
