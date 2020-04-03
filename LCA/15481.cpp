//그래프와 MST
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

struct A{
    vector<int> root;

    A(int n): root(n+1){
        for(int i=1; i<=n; i++)
            root[i] = i;
    }

    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }

    void merge(int a, int b){
        int r1 = find(a), r2 = find(b);
        root[r2] = r1;
    }

    bool connect(int a, int b){
        return find(a) == find(b);
    }
};

vector<vector<pair<int,int> > > v(200005);
pair<int,int> par[200005][20];
int depth[200005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;
        if(!par[next][0].fst){
            depth[next] = depth[vtx]+1;
            par[next][0].fst = vtx;
            par[next][0].snd = v[vtx][i].snd;
            dfs(next);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    A tree(n+1);
    vector<pair<int,pair<int,int> > > q;

    priority_queue<pair<int,pair<int,int> > > pq;
    for(int i=0; i<m; i++){
        int s,f,c;
        scanf("%d%d%d",&s,&f,&c);
        pq.push(mp(-c,mp(s,f)));
        q.pb(mp(s,mp(f,c)));
    }

    lli sum = 0;
    while(!pq.empty()){
        int cost = -pq.top().fst;
        int s = pq.top().snd.fst;
        int f = pq.top().snd.snd;
        pq.pop();

        if(tree.connect(s,f)) continue;
        sum += (lli)cost;
        tree.merge(s,f);
        v[s].pb(mp(f,cost)), v[f].pb(mp(s,cost));
    }

    par[1][0].fst = 1, dfs(1);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            pair<int,int> tmp = par[j][i-1];
            par[j][i].fst = par[tmp.fst][i-1].fst;
            par[j][i].snd = max(tmp.snd,par[tmp.fst][i-1].snd);
        }
    }

    for(int i=0; i<q.size(); i++){
        int a = q[i].fst;
        int b = q[i].snd.fst;
        int c = q[i].snd.snd;

        if(depth[a] < depth[b]) swap(a,b);

        int cut = 0, gap = depth[a] - depth[b];
        for(int i=0; (1<<i)<=gap; i++){
            if((1<<i) & gap){
                cut = max(cut,par[a][i].snd);
                a = par[a][i].fst;
            }
        }

        if(a != b){
            for(int i=19; i>=0; i--){
                if(par[a][i].fst != par[b][i].fst){
                    cut = max(cut,par[a][i].snd);
                    a = par[a][i].fst;
                    cut = max(cut,par[b][i].snd);
                    b = par[b][i].fst;
                }
            }
            cut = max(cut, max(par[a][0].snd,par[b][0].snd));
        }
        cout << sum + (lli)c - (lli)cut << '\n';
    }
}
