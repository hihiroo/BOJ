//단절점
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(10005);
int visit[10005], cnt;
vector<int> ans;

int dfs(int vtx, bool root){
    visit[vtx] = ++cnt;

    int par = visit[vtx], child=0, bcc=0;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];

        if(!visit[next]){
            int k = dfs(next,0);
            par = min(par,k);
            child++;

            if(!root && k >= visit[vtx]) bcc = 1;
        }
        else par = min(par,visit[next]);
    }

    if(root && child >= 2) bcc = 1;
    if(bcc) ans.pb(vtx);

    return par;
}

int main(){
    cinFast();
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].pb(b), v[b].pb(a);
    }

    for(int i=1; i<=n; i++)
        if(!visit[i]) dfs(i,1);

    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
}
