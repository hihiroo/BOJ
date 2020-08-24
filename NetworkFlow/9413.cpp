//제주도 관광
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct E{
    int next, c, f, cost;
    E *rev;

    E(int vtx, int c, int cost): next(vtx), c(c), f(0), cost(cost){}

    int canFlow(){ return c - f; }

    void makeFlow(int poss){
        f += poss;
        rev->f -= poss;
    }
};

vector<vector<E*> > v(605);

int flow(int s, int e){
    int ans = 0, cnt = 0;
    while(1){
        vector<pair<int,int> > par(605,mp(-1,-1));
        vector<int> dist(605,1e8);
        vector<bool> inQ(605);
        queue<int> q;

        q.push(s), inQ[s] = 1, dist[s] = 0;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            inQ[vtx] = 0;

            for(int i=0; i<v[vtx].size(); i++){
                E *edge = v[vtx][i];
                int cost = edge->cost;
                int next = edge->next;

                if(edge->canFlow() > 0 && dist[next] > dist[vtx] + cost){
                    dist[next] = dist[vtx] + cost;
                    par[next] = mp(vtx,i);
                    if(!inQ[next]){
                        inQ[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        if(par[e].fst == -1) break;

        for(int i=e; i!=s; i=par[i].fst){
            E *edge = v[par[i].fst][par[i].snd];
            edge->makeFlow(1);
            ans += edge->cost;
        }
        if(++cnt == 2) break;
    }
    return ans;
}

int main(){
    cinFast();
    int t, n, m;
    cin >> t;

    while(t--){
        cin >> n >> m;
        for(int i=0; i<=2*n+1; i++) v[i].clear();

        for(int i=1; i<=n; i++){
            //소스랑 정점 연결
            E *uv = new E(i,1,-1);
            E *vu = new E(0,0,1);
            uv->rev = vu, vu->rev = uv;
            v[0].pb(uv), v[i].pb(vu);

            //들어가는 정점, 나가는 정점 연결
            uv = new E(n+i,1,0);
            vu = new E(i,0,0);
            uv->rev = vu, vu->rev = uv;
            v[i].pb(uv), v[n+i].pb(vu);


            //나가는 정점이랑 싱크 연결
            uv = new E(2*n+1,1,0);
            vu = new E(n+i,0,0);
            uv->rev = vu, vu->rev = uv;
            v[n+i].pb(uv), v[2*n+1].pb(vu);
        }

        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;

            //a나가는 정점이랑 b들어오는 정점 연결
            E *uv = new E(b,1,-1);
            E *vu = new E(n+a,0,1);
            uv->rev = vu, vu->rev = uv;
            v[n+a].pb(uv), v[b].pb(vu);
        }

        cout << -flow(0,2*n+1) << '\n';
    }
}
