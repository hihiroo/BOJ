//컨닝2

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct E{
    int vtx,c,f;
    E *rev;

    E(int vtx, int c, int f): vtx(vtx),c(c),f(f){}

    int possible(){return c-f;}

    void push_flow(int amt){
        f += amt;
        rev->f -= amt;
    }
};

vector<vector<E*> > v(6500);

void addEdge(int s, int e, int c){
    E *sf = new E(e,1,0), *fs = new E(s,0,0);

    sf->rev = fs, fs->rev = sf;
    v[s].pb(sf), v[e].pb(fs);

}

int flow(int s, int e){
    int ans = 0;
    while(1){
        queue<int> q;
        vector<int> par(6500,-1);
        E* path[6500];

        par[s] = s;
        q.push(s);

        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                E *tmp = v[vtx][i];
                int next = tmp->vtx;

                if(par[next] == -1 && tmp->possible() > 0){
                    par[next] = vtx;
                    path[next] = tmp;
                    q.push(next);
                }
            }
        }

        if(par[e] == -1) break;
        int poss = 1e8;
        for(int i=e; i!=s; i=par[i])
            poss = min(poss,path[i]->possible());

        for(int i=e; i!=s; i=par[i])
            path[i]->push_flow(poss);

        ans += poss;
    }
    return ans;
}


char arr[85][85];
int n,m,dir[6][2] = {{1,1},{-1,-1},{-1,1},{1,-1},{0,1},{0,-1}};

bool safe(int y, int x){
    return y>0 && y<=n && x>0 && x<=m;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int sum = 0;

        for(int i=0; i<=n*m+1; i++)
            v[i].clear();


        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>arr[i][j];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j] == 'x') continue;
                sum++;

                if(j % 2 == 1){
                    addEdge((i-1)*m+j,n*m+1,1);
                    continue;
                }

                addEdge(0,(i-1)*m+j,1);
                for(int k=0; k<6; k++){
                    int ny = i + dir[k][0];
                    int nx = j + dir[k][1];
                    if(safe(ny,nx) && arr[ny][nx] != 'x'){
                        addEdge((i-1)*m+j,(ny-1)*m+nx,1);
                    }
                }
            }
        }
        cout<<sum-flow(0,n*m+1)<<'\n';
    }
}
