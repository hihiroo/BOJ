//서강 그라운드
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dist[105][105], item[105];

int main(){
    fill(&dist[0][0], &dist[104][104],1e8);

    int n,m,r;
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++)scanf("%d",&item[i]);
    for(int i=0; i<r; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) dist[i][j] = 0;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++)
            if(dist[i][j] <= m) cnt += item[j];
        ans = max(ans,cnt);
    }
    cout<<ans;
}
