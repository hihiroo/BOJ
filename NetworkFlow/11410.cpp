//칙칙폭폭
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct E{
    int c,f,cost,next;
    E *rev;

    E(int next, int c, int cost):next(next),c(c),cost(cost),f(0){}

    int canFlow(){return c-f;}
    void makeFlow(int poss){f += poss, rev->f-=poss;}
};

vector<vector<E*> > v(55);
int needs[55][55];

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> dist(55,1e9);
        vector<bool> inQ(55);
        vector<pair<int,int> > par(55,mp(-1,-1));
        queue<int> q;

        q.push(s), dist[s] = 0, inQ[s] = 1;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            inQ[vtx] = 0;

            for(int i=0; i<v[vtx].size(); i++){
                E *edge = v[vtx][i];
                int next = edge->next;
                int cost = dist[vtx] + edge->cost;

                if(edge->canFlow() > 0 && dist[next] > cost){
                    dist[next] = cost;
                    par[next] = mp(vtx,i);

                    if(!inQ[next]){
                        inQ[next] = 1;
                        q.push(next);
                    }
                }
            }
        }

        if(par[e].fst == -1) break;

        int poss = 1e9;
        for(int i=e; i!=s; i=par[i].fst){
            E *edge = v[par[i].fst][par[i].snd];
            poss = min(poss,edge->canFlow());
        }

        for(int i=e; i!=s; i=par[i].fst){
            E *edge = v[par[i].fst][par[i].snd];
            edge->makeFlow(poss);
            ans += poss*edge->cost;
        }
    }
    return ans;
}

int main(){
    cinFast();
    int n,p;
    cin >> n >> p;

    E *uv = new E(1,p,0), *vu = new E(0,0,0);
    uv->rev = vu, vu->rev = uv;
    v[0].pb(uv), v[1].pb(vu);

    for(int i=1; i<n; i++){
        uv = new E(i+1,1e8,0), vu = new E(i,0,0);
        uv->rev = vu, vu->rev = uv;
        v[i].pb(uv), v[i+1].pb(vu);

        for(int j=i+1; j<=n; j++) cin >> needs[i][j];
    }

    for(int i=1; i<n; i++){
        for(int j=i+1, a; j<=n; j++){
            cin >> a;

            uv = new E(j,needs[i][j],-a);
            vu = new E(i,0,a);
            uv->rev = vu, vu->rev = uv;
            v[i].pb(uv), v[j].pb(vu);
        }
    }
    cout << -flow(0,n);
}
