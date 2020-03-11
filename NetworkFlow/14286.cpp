//간선 끊어가기 2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct E{
    int now, vtx, c, f;
    E *rev;

    E(int now, int vtx, int c):
        now(now), vtx(vtx), c(c),f(0){}

    int possible(){return c-f;}

    void push_flow(int amt){
        f += amt;
        rev->f -= amt;
    }
};

vector<vector<E*> > v(505);

int flow(int s, int e){
    int ans = 0;

    while(1){
        queue<int> q;
        vector<int> par(505,-1);
        E *path[505];
        q.push(s), par[s] = s;

        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                E *tmp = v[vtx][i];
                int next = tmp->vtx, c = tmp->c, f = tmp->f;
                if(c > f && par[next] == -1){
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

int main(){
    int n,m;
    cin>>n>>m;

    for(; m>0; m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        E *sf = new E(a,b,c), *fs = new E(b,a,0);
        sf->rev = fs, fs->rev = sf;
        v[a].pb(sf), v[b].pb(fs);

        sf = new E(b,a,c), fs = new E(a,b,0);
        sf->rev = fs, fs->rev = sf;
        v[b].pb(sf), v[a].pb(fs);
    }

    int s,t;
    cin>>s>>t;
    cout<<flow(s,t);
}
