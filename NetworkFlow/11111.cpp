#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct E{
    int vtx, c, f, cost;
    E *rev;

    E(int vtx, int c, int cost):
        vtx(vtx),c(c),cost(cost),f(0){}

    int possible(){return c-f;}

    void push_flow(int amt){
        f += amt;
        rev->f -= amt;
    }
};
vector<vector<E*> > v(3000);

void connect(int s, int e, int c, int cost){
    E *sf = new E(e,c,cost), *fs = new E(s,0,-cost);
    sf->rev = fs, fs->rev = sf;
    v[s].pb(sf), v[e].pb(fs);
}

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(3000,-1), dist(3000,1e8);
        vector<bool> inQ(3000,0);
        queue<int> q;
        E *path[3000];

        q.push(s), inQ[s] = true, dist[s] = 0;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            inQ[vtx] = false;

            for(int i=0; i<v[vtx].size(); i++){
                E *tmp = v[vtx][i];
                int next = tmp->vtx, cost = tmp->cost;
                int c = tmp->c, f = tmp->f;

                if(c > f && dist[next] > dist[vtx]+cost){
                    dist[next] = dist[vtx] + cost;
                    par[next] = vtx, path[next] = tmp;
                    if(!inQ[next]){
                        inQ[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        if(par[e] == -1 || dist[e] > 0) break;

        int poss = 1e8;
        for(int i=e; i!=s; i=par[i])
            poss = min(poss,path[i]->possible());

        for(int i=e; i!=s; i=par[i])
            path[i]->push_flow(poss);

        ans += dist[e];
    }
    return -ans;
}

int cost[6][6] = {{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},
{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, n,m;


bool safe(int y, int x){
    return y>0 && y<=n && x>0 && x<=m;
}

int main(){
    cin>>n>>m;

    char arr[55][55];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if((i+j)%2) connect(0,(i-1)*m+j,1,0);
            else connect((i-1)*m+j,n*m+1,1,0);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if((i+j)%2 == 0) continue;
            int vtx = arr[i][j]-'A';

            for(int k=0; k<4; k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                if(safe(ny,nx)){
                    int vtx2 = arr[ny][nx]-'A';
                    connect((i-1)*m+j,(ny-1)*m+nx,1,-cost[vtx][vtx2]);
                }
            }
        }
    }

    cout<<flow(0,n*m+1);
}
