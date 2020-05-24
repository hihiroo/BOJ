//두번째로 작은 스패닝 트리

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair
#define pii pair<int,int>

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

struct Q{
    int a, b, cost;
    Q(int a, int b, int c): a(a),b(b),cost(c){}
};

vector<Q> query;
vector<vector<pii> > v(50005);
int par[50005][20], depth[50005];
int large1[50005][20], large2[50005][20];


/* function */

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;
        int cost = v[vtx][i].snd;

        if(!par[next][0]){
            depth[next] = depth[vtx] + 1;
            par[next][0] = vtx;
            large1[next][0] = cost;

            dfs(next);
        }
    }
}

priority_queue<pair<int,pii> > input_E(int E){
    priority_queue<pair<int,pii> > pq;

    for(int i=0; i<E; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        pq.push(mp(-c,mp(a,b)));
    }

    return pq;
}

int kruskal(int V, int E){
    priority_queue<pair<int,pii> > pq;
    pq = input_E(E);

    A tree(V);

    int sum = 0;
    while(!pq.empty()){
        int cost = -pq.top().fst;
        int a = pq.top().snd.fst;
        int b = pq.top().snd.snd;
        pq.pop();

        if(tree.connect(a,b)){
            Q tmp(a,b,cost);
            query.pb(tmp);
            continue;
        }

        sum += cost;
        tree.merge(a,b);

        v[a].pb(mp(b,cost));
        v[b].pb(mp(a,cost));
    }
    return sum;
}

int find_snd(int a, int b, int c, int d){
    int arr[4] = {a,b,c,d};
    sort(arr,arr+4);
    for(int i=2; i>=0; i--)
        if(arr[i] != arr[3]) return arr[i];
    return -1;
}

void build_table(int V){
    memset(large2,-1,sizeof(large2));

    par[1][0] = 1;
    dfs(1);

    for(int i=1; i<20; i++){
        for(int k=1; k<=V; k++){
            int u = par[k][i-1];
            large2[k][i] = find_snd(large1[k][i-1],
                                    large1[u][i-1],
                                    large2[k][i-1],
                                    large2[u][i-1]);
            large1[k][i] = max(large1[k][i-1],large1[u][i-1]);
            par[k][i] = par[u][i-1];
        }
    }
}

int lca(){
    int res = 1e6;

    for(int i=0; i<query.size(); i++){
        int a = query[i].a;
        int b = query[i].b;
        int cost = query[i].cost;

        if(depth[a] < depth[b]) swap(a,b);

        int gap = depth[a] - depth[b];
        int big1 = -1, big2 = -1;

        for(int i=19; i>=0; i--){
            if(gap & (1 << i)){
                big2 = find_snd(big1,big2,
                                large1[a][i],large2[a][i]);
                big1 = max(big1,large1[a][i]);
                a = par[a][i];
            }
        }

        if(a != b){
            for(int i=19; i>=0; i--){
                if(par[a][i] == par[b][i]) continue;

                big2 = find_snd(big1,big2,large1[a][i],large2[a][i]);
                big1 = max(big1,large1[a][i]);
                big2 = find_snd(big1,big2,large1[b][i],large2[b][i]);
                big1 = max(big1,large1[b][i]);

                a = par[a][i];
                b = par[b][i];
            }
            big2 = find_snd(big1,big2,large1[a][0],large2[b][0]);
            big1 = max(big1,max(large1[a][0],large1[b][0]));
        }

        if(big1 != cost) res = min(res, cost-big1);
        else if(big2 != -1) res = min(res,cost-big2);
    }
    return res == 1e6 ? -1 : res;
}

int main(){
    int V, E;
    cin >> V >> E;

    int sum = kruskal(V,E);
    if(E-query.size() != V-1) return cout<<-1,0;
    
    build_table(V);

    int ans = lca();
    if(ans == -1) return cout << -1,0;
    cout << ans + sum;
}
