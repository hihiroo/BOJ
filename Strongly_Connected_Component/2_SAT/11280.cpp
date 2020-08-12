//2-SAT-3
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(20005);
int visit[20005], scc[20005], num, cnt;
stack<int> s;

int dfs(int vtx){
    visit[vtx] = ++cnt;
    s.push(vtx);

    int par = visit[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visit[next]) par = min(par,dfs(next));
        else if(!scc[next]) par = min(par,visit[next]);
    }

    if(par == visit[vtx]){
        num++;
        while(1){
            int comp = s.top();
            s.pop();
            scc[comp] = num;
            if(comp == vtx) break;
        }
    }

    return par;
}

int oppo(int a, int n){
    if(a <= n) return a + n;
    return a - n;
}

int main(){
    cinFast();
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(b < 0) b = -b;
        else b += n;
        if(a < 0) a = -a;
        else a += n;

        v[oppo(a,n)].pb(b);
        v[oppo(b,n)].pb(a);
    }

    for(int i=1; i<=2*n; i++)
        if(!visit[i]) dfs(i);

    for(int i=1; i<=n; i++)
        if(scc[i] == scc[i+n]) return cout << 0,0;

    cout << 1;
}
