//단절선
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(100005);
int visit[100005], cnt;
vector<pair<int,int> > ans;

int dfs(int vtx, int parent){
    visit[vtx] = ++cnt;

    int par = visit[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];

        if(next == parent) continue;

        if(!visit[next]){
            int k = dfs(next,vtx);
            par = min(par,k);

            if(k > visit[vtx])
                ans.pb({min(vtx,next),max(vtx,next)});
        }
        else par = min(par,visit[next]);
    }
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
        if(!visit[i]) dfs(i,-1);

    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].fst << " " << ans[i].snd << '\n';
}
