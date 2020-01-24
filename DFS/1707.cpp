//이분 그래프
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > adj(20005);
int group[20005], poss;

void dfs(int vtx){
    if(!poss) return;
    for(int i=0; i<adj[vtx].size(); i++){
        int next = adj[vtx][i];
        if(group[next] == group[vtx]){
            poss = 0;
            return;
        }
        if(group[next] == -1){
            group[next] = !group[vtx];
            dfs(next);
        }
    }
    return;
}

int main(){
    int k;
    cin>>k;
    for(; k>0; k--){
        int v,e;
        cin>>v>>e;
        for(int i=1; i<=v; i++)
            adj[i].clear();
        memset(group,-1,sizeof(group));

        for(int i=0; i<e; i++){
            int s, f;
            scanf("%d%d",&s,&f);
            adj[s].pb(f), adj[f].pb(s);
        }

        poss = 1;
        for(int i=1; i<=v; i++){
            if(group[i] == -1){
                group[i] = 0;
                dfs(i);
            }
        }
        if(!poss) printf("NO\n");
        else printf("YES\n");
    }
}



