// 안전한 비상연락망
#include <bits/stdc++.h>
using namespace std;
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define mp make_pair

struct Union{
    vector<int> root;
    Union(int n): root(n+1){
        for(int i=1; i<=n; i++) root[i] = i;
    }
    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }
    void merge(int a, int b){ // b의 루트 밑에 a의 루트 연결
        int r1 = find(a), r2 = find(b);
        root[r1] = r2;
    }
    bool connected(int a, int b){
        return find(a) == find(b);
    }
};

struct E{
    int a, b, id;
    lli c;
    bool isMST;
};

vector<vector<pair<int,lli> > > mst(100005);
int depth[100005], par[100005][20];

void dfs(int vtx){
    for(int i=0; i<mst[vtx].size(); i++){
        int next = mst[vtx][i].fst;

        if(!par[next][0]){
            depth[next] = depth[vtx] + 1;
            par[next][0] = vtx;
            dfs(next);
        }
    }
}

void lca_init(int n){
    par[1][0] = 1, dfs(1);

    for(int j=1; j<20; j++){
        for(int i=1; i<=n; i++){
            int tmp = par[i][j-1];
            par[i][j] = par[tmp][j-1];
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int gap = depth[a] - depth[b];

    for(int i=0; (1<<i)<=gap; i++){
        if((1<<i)&gap) a = par[a][i];
    }
    if(a == b) return a;

    for(int i=19; i>=0; i--){
        if(par[a][i] == par[b][i]) continue;
        a = par[a][i], b = par[b][i];
    }
    return par[a][0];
}

int main(){
    cinFast();

    int n, m;
    cin >> n >> m;

    priority_queue<pair<lli,int> > pq;
    vector<E> edge(m);

    for(int i=0; i<m; i++){
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
        edge[i].id = i;
        pq.push(mp(-edge[i].c,i));
    }

    Union tree(n);
    vector<pair<lli,int> > notMST;

    lli sum = 0;
    while(!pq.empty()){
        int id = pq.top().snd;
        int a = edge[id].a, b = edge[id].b;
        lli c = edge[id].c;
        pq.pop();

        if(tree.connected(a,b)){
            edge[id].isMST = 0;
            notMST.pb(mp(c,id));
            continue;
        }
        tree.merge(a,b);
        sum += c, edge[id].isMST = 1;
        mst[a].pb(mp(b,c)), mst[b].pb(mp(a,c));
    }

    lca_init(n);
    sort(notMST.begin(), notMST.end());
    Union replaced(n);
    vector<int> ans(n+1,-1);

    for(int i=0; i<notMST.size(); i++){
        int id = notMST[i].snd;
        int a = edge[id].a, b = edge[id].b;
        lli c = edge[id].c;

        int r = lca(a,b);
        while(1){
            a = replaced.find(a);
            if(depth[a] <= depth[r]) break;
            ans[a] = c;
            replaced.merge(a,par[a][0]);
        }
        while(1){
            b = replaced.find(b);
            if(depth[b] <= depth[r]) break;
            ans[b] = c;
            replaced.merge(b,par[b][0]);
        }
    }
    for(int i=0; i<m; i++){
        if(edge[i].isMST){
            int a = edge[i].a, b = edge[i].b;
            if(depth[a] < depth[b]) swap(a,b);

            if(ans[a] == -1) cout << -1 << '\n';
            else cout << sum - edge[i].c + ans[a] << '\n';
        }
        else cout << sum << '\n';
    }
}