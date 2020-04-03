//정점들의 거리
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

pair<int,int> par[40005][20];
vector<vector<pair<int,int> > > v(40005);
int depth[40005];

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;
        if(!par[next][0].fst){
            depth[next] = depth[vtx]+1;
            par[next][0] = mp(vtx,v[vtx][i].snd);
            dfs(next);
        }
    }
}

int main(){
    int n,m;
    cin >> n;

    for(int i=1; i<n; i++){
        int s,f,cost;
        scanf("%d%d%d",&s,&f,&cost);
        v[s].pb(mp(f,cost));
        v[f].pb(mp(s,cost));
    }

    par[1][0].fst = 1;
    dfs(1);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            pair<int,int> tmp = par[j][i-1];
            par[j][i].fst = par[tmp.fst][i-1].fst;
            par[j][i].snd = par[j][i-1].snd + par[tmp.fst][i-1].snd;
        }
    }

    cin >> m;

    while(m--){
        int a, b, ans = 0;
        scanf("%d%d",&a,&b);

        if(depth[a] < depth[b]) swap(a,b);

        int gap = depth[a] - depth[b];
        for(int i=0; (1<<i)<=gap; i++){
            if((1<<i)&gap){
                ans += par[a][i].snd;
                a = par[a][i].fst;
            }
        }

        if(a != b){
            for(int i=15; i>=0; i--){
            if(par[a][i].fst != par[b][i].fst){
                    ans += par[a][i].snd;
                    a = par[a][i].fst;
                    ans += par[b][i].snd;
                    b = par[b][i].fst;
                }
            }
            ans += par[a][0].snd + par[b][0].snd;
        }

        printf("%d\n",ans);
    }
}
