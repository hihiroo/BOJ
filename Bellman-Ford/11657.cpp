//타임머신
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(505);
int dist[505];

int main(){
    fill(dist,dist+505,1e8);

    int n,m,a,b,c;
    cin>>n>>m;
    for(; m>0; m--){
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
    }

    dist[1] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<v[j].size(); k++){
                int next = v[j][k].fst;
                int cost = v[j][k].snd;
                if(dist[j] != 1e8 && dist[next] > dist[j] + cost){
                    dist[next] = dist[j] + cost;
                    if(i == n-1) return cout<<-1,0;
                }
            }
        }
    }
    for(int i=2; i<=n; i++)
        printf("%d\n",dist[i] == 1e8 ? -1 : dist[i]);
}

