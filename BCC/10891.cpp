// Cactus? Not Cactus?

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
vector<vector<pair<int,int> > > bcc;
int visit[100005], cnt;
stack<pair<int,int> > s;

int dfs(int vtx, int pre){
    visit[vtx] = ++cnt;

    int par = visit[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];

        if(next == pre) continue;

        if(visit[next] < visit[vtx])
            s.push(mp(vtx,next));

        if(visit[next]) par = min(par, visit[next]);
        else{
            int tmp = dfs(next,vtx);
            par = min(par,tmp);

            if(tmp >= visit[vtx]){
                vector<pair<int,int> > comp;
                while(1){
                    pair<int,int> k = s.top();
                    s.pop();

                    comp.pb(k);
                    if(k == mp(vtx,next)) break;
                }
                if(comp.size() > 1) bcc.pb(comp);
            }
        }
    }
    return par;
}

int main(){
    cinFast();
    int n,e;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        v[a].pb(b), v[b].pb(a);
    }

    for(int i=1; i<=n; i++)
        if(!visit[i]) dfs(i,-1);

    vector<int> chk(n+5,1e8);
    for(int i=0; i<bcc.size(); i++){
        int ecnt = bcc[i].size(), vcnt = 0;

        for(int j=0; j<bcc[i].size(); j++){
            int a = bcc[i][j].fst;
            int b = bcc[i][j].snd;

            if(chk[a]<i) return cout << "Not cactus",0;
            if(chk[b]<i) return cout << "Not cactus",0;
            if(chk[a] == 1e8) vcnt++;
            if(chk[b] == 1e8) vcnt++;
            chk[a] = i, chk[b] = i;
        }
        if(vcnt!=ecnt) return cout << "Not cactus",0;
    }

    cout << "Cactus";
}
