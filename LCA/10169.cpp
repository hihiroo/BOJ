// 안전한 비상연락망
#include <bits/stdc++.h>
using namespace std;
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define mp make_pair

struct T{
    vector<int> root;
    T(int n): root(n+1){
        for(int i=1; i<=n; i++) root[i] = i;
    }
    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }
    void merge(int a, int b){
        int r1 = find(a), r2 = find(b);
        root[r1] = r2;
    }
    bool connected(int a, int b){
        return find(a) == find(b);
    }
};

vector<vector<pair<int,lli> > > mst(100005), notMST(100005);
vector<vector<pair<lli,int> > > poss(100005);
int depth[100005], par[100005][20];

void dfs(int vtx){
    for(int i=0; i<mst[vtx].size(); i++){
        int next = mst[vtx][i].fst;
        if(!par[next][0]){
            par[next][0] = vtx;
            depth[next] = depth[vtx] + 1;
            dfs(next);
        }
    }
}

void lca_init(int n){
    par[1][0] = 1;
    dfs(1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<20; j++){
            int tmp = par[i][j-1];
            par[i][j] = par[tmp][j-1];
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int gap = depth[a] - depth[b];

    for(int i=0; (1<<i)<=gap; i++){
        if(gap & (1<<i)) a = par[a][i];
    }
    if(a == b) return a;

    for(int i=19; i>=0; i--){
        if(par[a][i] == par[b][i]) continue;
        a = par[a][i], b = par[b][i];
    }
    return par[a][0];
}

void find_new(int vtx){
    for(int i=0; i<mst[vtx].size(); i++){
        int next = mst[vtx][i].fst;

        if(depth[vtx] < depth[next]){
            find_new(next);
            for(int j=0; j<poss[next].size(); j++){
                if(poss[next][j].snd != vtx) poss[vtx].pb(poss[next][j]);
            }
        }
    }
    sort(poss[vtx].begin(), poss[vtx].end());
}

int main(){
    cinFast();

    int n, m;
    cin >> n >> m;

    priority_queue<pair<lli,pair<int,int> > > pq;
    queue<pair<int,pair<int,lli> > > q;
    for(int i=0; i<m; i++){
        int a, b;
        lli c;
        cin >> a >> b >> c;
        pq.push(mp(-c,mp(a,b)));
        q.push(mp(a,mp(b,c)));
    }

    T tree(n);
    map<pair<int,pair<int,lli> >, bool> isInMST;
    lli sum = 0;

    while(!pq.empty()){
        int a = pq.top().snd.fst;
        int b = pq.top().snd.snd;
        lli c = -pq.top().fst;
        pq.pop();

        if(tree.connected(a,b)){
            notMST[a].pb(mp(b,c));
            continue;
        }
        tree.merge(a,b);
        sum += c, isInMST[mp(a,mp(b,c))] = 1;
        mst[a].pb(mp(b,c));
        mst[b].pb(mp(a,c));
    }

    lca_init(n);

    for(int i=1; i<=n; i++){
        for(int j=0; j<notMST[i].size(); j++){
            int vtx = notMST[i][j].fst;
            lli c = notMST[i][j].snd;

            int r = lca(i,vtx);
            if(i != r) poss[i].pb(mp(c,r));
            if(vtx != r) poss[vtx].pb(mp(c,r));
        }
    }

    find_new(1);

    while(!q.empty()){
        int a = q.front().fst;
        int b = q.front().snd.fst;
        lli c = q.front().snd.snd;
        q.pop();

        if(isInMST[mp(a,mp(b,c))]){
            if(depth[a] < depth[b]) swap(a,b);
            if(poss[a].empty()) cout << -1 << '\n';
            else cout << sum - c + poss[a][0].fst << '\n';
        }
        else cout << sum << '\n';
    }
}
