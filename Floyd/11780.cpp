//플로이드2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dist[105][105], par[105][105], visit[105];
vector<int> ans;

void f(int s, int e){
    if(s == e){
        if(visit[s]) return;
        ans.pb(s), visit[s] = 1;
        return;
    }

    int k = par[s][e];
    if(k == 0){
        f(s,s), f(e,e);
        return;
    }

    f(s,k);
    if(!visit[k])
        ans.pb(k), visit[k] = 1;
    f(k,e);
}

int main(){
    fill(&dist[0][0],&dist[104][104],1e8);

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) dist[i][i] = 0;

    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b] = min(dist[a][b],c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = k;
                }
            }
        }
    }

    for(int i=1; i<=n; i++,printf("\n"))
        for(int j=1; j<=n; j++)
            printf("%d ",dist[i][j] == 1e8 ? 0: dist[i][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == 0){
                printf("0\n");
                continue;
            }
            ans.clear();
            memset(visit,0,sizeof(visit));

            f(i,j);
            printf("%d ",ans.size());
            for(int i=0; i<ans.size(); i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
}
