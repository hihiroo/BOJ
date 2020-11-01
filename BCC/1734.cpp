// 교통체계
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(100005), block;
bool isArti[100005];
map<pair<int,int>,int> bridge;
int n, e, inBcc[100005];

pair<int,int> eOrder(int a, int b){
    return mp(min(a,b),max(a,b));
}

namespace bccN{
    int cnt = 0, visit[100005];
    stack<pair<int,int> > s;
    vector<vector<pair<int,int> > > bcc;

    int dfs(int vtx, int pre){
        visit[vtx] = ++cnt;

        int par = visit[vtx];
        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];

            if(next == pre) continue;
            if(visit[next] < visit[vtx]) s.push(mp(vtx,next));

            if(visit[next]) par = min(par,visit[next]);
            else{
                int tmp = dfs(next,vtx);
                par = min(par,tmp);

                if(tmp >= visit[vtx]){
                    if(pre != -1 || v[vtx].size() > 1) isArti[vtx] = 1;
                    if(tmp > visit[vtx])
                        bridge[eOrder(vtx,next)] = n+bcc.size()+1;

                    vector<pair<int,int> > comp;
                    while(1){
                        pair<int,int> k = s.top();
                        s.pop();
                        comp.pb(k);
                        if(k == mp(vtx,next)) break;
                    }
                    bcc.pb(comp);
                }
            }
        }
        return par;
    }

    void buildBlock(){
        dfs(1,-1);
        block = vector<vector<int> >(n+bcc.size()+5);

        // bcc 블럭의 번호는 n+1 ~ n+bccsize, 단절점과 bcc 연결
        for(int i=0; i<bcc.size(); i++){
            for(int j=0; j<bcc[i].size(); j++){
                int a = bcc[i][j].fst;
                int b = bcc[i][j].snd;
                if(isArti[a]) block[a].pb(n+i+1);
                if(isArti[b]) block[b].pb(n+i+1);
                inBcc[a] = n+i+1, inBcc[b] = n+i+1;
            }
        }

        for(int i=1; i<=n; i++){// 중복제거 및 bcc에 단절점 연결
            sort(block[i].begin(),block[i].end());
            block[i].erase(unique(block[i].begin(),block[i].end()),block[i].end());

            for(int j=0; j<block[i].size(); j++)
                block[block[i][j]].pb(i);
        }
    }
}
// 1번 쿼리 : 간선이 단절선인지, 어떤 bcc에 속하는지
// 2번 쿼리 : 정점이 단절점인지
namespace lca{
    int cnt = 0, depth[600005], visit[600005], par[600005][30];

    void dfs(int vtx){
        visit[vtx] = ++cnt;

        for(int i=0; i<block[vtx].size(); i++){
            int next = block[vtx][i];
            if(!visit[next]){
                depth[next] = depth[vtx]+1;
                par[next][0] = vtx;
                dfs(next);
            }
        }
    }

    void buildPar(){
        for(int i=1; i<=n; i++) if(!visit[i] && isArti[i]) dfs(i);

        for(int i=1; i<30; i++){
            for(int j=1; j<600001; j++){
                int k = par[j][i-1]; // j의 2^i-1번째 부모
                par[j][i] = par[k][i-1]; // j의 2^i번째 부모는 2^i-1번째 부모의 2^i-1번째 부모
            }
        }
    }

    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a,b); // a가 b보다 밑에 있도록 바꿔줌
        int gap = depth[a]-depth[b];

        for(int i=0; i<30; i++){ // a와 b를 같은 깊이로 맞춰줌
            if(gap & (1<<i)) a = par[a][i];
        }

        if(a == b) return a;

        for(int i=29; i>=0; i--)
            if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];

        return par[a][0];
    }

    bool solveQ(int A, int B, int C){
        int w = lca(A,B), ac = lca(A,C), bc = lca(B,C);
        if(ac == C || bc == C) return !(lca(w,C) == w);
        return true;
    }

    bool query(int q){
        int A, B, C, G1, G2;
        if(q == 1) cin >> A >> B >> G1 >> G2;
        if(q == 2) cin >> A >> B >> C;

        if(q == 1 && bridge.count(eOrder(G1,G2)) == 0) return true;
        else if(q == 2 && !isArti[C]) return true;

        if(q == 1) C = bridge[eOrder(G1,G2)];
        if(!isArti[A]) A = inBcc[A];
        if(!isArti[B]) B = inBcc[B];

        return solveQ(A,B,C);
    }
}

int main(){
    cinFast();
    cin >> n >> e;

    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        v[a].pb(b), v[b].pb(a);
    }

    bccN::buildBlock();
    lca::buildPar();

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        lca::query(q) ? cout << "yes\n" : cout << "no\n";
    }
}
