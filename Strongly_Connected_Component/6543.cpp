//그래프의 싱크
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int visit[5005], scc[5005], out[5005], num, cnt;
bool finished[5005];
stack<int> s;
vector<vector<int> > v(5005);

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
            int node = s.top();
            s.pop();
            scc[node] = cnt;
            finished[node] = 1;
            if(node == vtx) break;
        }
    }

    return par;
}

int main(){
    cinFast();

    while(1){
        int n,m;
        cin >> n;
        if(n == 0) break;
        cin >> m;

        memset(visit,0,sizeof(visit));
        memset(scc,0,sizeof(scc));
        memset(out,0,sizeof(out));
        memset(finished,0,sizeof(finished));
        num = 0, cnt = 0;
        for(int i=1; i<=n; i++) v[i].clear();

        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            v[a].pb(b);
        }

        for(int i=1; i<=n; i++)
            if(!visit[i]) dfs(i);

        for(int i=1; i<=n; i++){
            for(int j=0; j<v[i].size(); j++){
                int next = v[i][j];
                if(scc[i] == scc[next]) continue;
                out[scc[i]]++;
            }
        }

        for(int i=1; i<=n; i++)
            if(!out[scc[i]]) cout << i << " ";
        cout << '\n';
    }
}
