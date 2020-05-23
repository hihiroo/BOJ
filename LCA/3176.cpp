//도로 네트워크
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair

int par[100005][30], lg[100005][30], st[100005][30];
int depth[100005];
vector<vector<pair<int,int> > > v(100005);

void dfs(int vtx){
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;

        if(!par[next][0]){
            depth[next] = depth[vtx]+1;

            par[next][0] = vtx;
            lg[next][0] = v[vtx][i].snd;
            st[next][0] = v[vtx][i].snd;

            dfs(next);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }

    par[1][0] = 1, st[1][0] = 1e6;
    dfs(1);

    for(int i=1; i<30; i++){
        for(int k=1; k<=n; k++){
            int v = par[k][i-1];
            par[k][i] = par[v][i-1];
            st[k][i] = min(st[k][i-1], st[v][i-1]);
            lg[k][i] = max(lg[k][i-1], lg[v][i-1]);
        }
    }

    int m;
    cin >> m;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);

        if(depth[a] < depth[b]) swap(a,b);

        int gap = depth[a] - depth[b];
        int ss = 1e6, ll = 0;

        for(int i=29; i>=0; i--){
            if(gap & (1<<i)){
                ll = max(ll, lg[a][i]);
                ss = min(ss,st[a][i]);
                a = par[a][i];
            }
        }

        if(a != b){
            for(int i=29; i>=0; i--){
                if(par[a][i] == par[b][i]) continue;
                ss = min(ss, min(st[a][i],st[b][i]));
                ll = max(ll, max(lg[a][i],lg[b][i]));
                a = par[a][i], b = par[b][i];
            }
            ss = min(ss,min(st[a][0],st[b][0]));
            ll = max(ll,max(lg[a][0],lg[b][0]));
        }
        printf("%d %d\n",ss,ll);
    }
}
