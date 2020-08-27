//ATM
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(500005);
int visit[500005], num, cnt, scc[500005];
int money[500005], sum[500005];
bool finished[500005], rest[500005];
stack<int> s;

int dfs(int vtx){
    visit[vtx] = ++num;
    s.push(vtx);

    int par = visit[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visit[next]) par = min(par,dfs(next));
        else if(!finished[next]) par = min(par,visit[next]);
    }

    if(par == visit[vtx]){
        cnt++;
        while(1){
            int comp = s.top();
            s.pop();

            finished[comp] = 1;
            scc[comp] = cnt;
            sum[cnt] += money[comp];

            if(comp == vtx) break;
        }
    }
    return par;
}

int main(){
    cinFast();
    int n,m, start, p;
    cin >> n >> m;

    for(int i=0,a,b; i<m; i++){
        cin >> a >> b;
        v[a].pb(b);
    }

    for(int i=1; i<=n; i++) cin >> money[i];

    for(int i=1; i<=n; i++)
        if(!visit[i]) dfs(i);

    cin >> start >> p;
    start = scc[start];

    for(int i=0,a; i<p; i++){
        cin >> a;
        rest[scc[a]] = 1;
    }

    vector<vector<int> > sccV(cnt+1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            int next = v[i][j];

            if(scc[i] == scc[next]) continue;
            sccV[scc[i]].pb(scc[next]);
        }
    }

    vector<int> dist(cnt+1,0), inQ(cnt+1);
    queue<int> q;
    q.push(start), inQ[start] = 1;
    dist[start] = sum[start];

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        inQ[vtx] = 0;

        for(int i=0; i<sccV[vtx].size(); i++){
            int next = sccV[vtx][i];
            if(dist[next] < dist[vtx] + sum[next]){
                dist[next] = dist[vtx] + sum[next];
                if(!inQ[next]){
                    inQ[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=cnt; i++)
        if(rest[i]) ans = max(ans,dist[i]);

    cout << ans;
}
