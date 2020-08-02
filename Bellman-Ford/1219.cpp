//오민식의 고민
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

lli earn[105];
vector<vector<pair<int,int> > > v(105);
bool cango[105][105];

int main(){
    cinFast();
    int n,s,e,m;
    cin >> n >> s >> e >> m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].pb(mp(b,c));
        cango[a][b] = 1;
    }

    for(int i=0; i<n; i++){
        cin >> earn[i];
        cango[i][i] = 1;
    }

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cango[i][j] |= (cango[i][k]&&cango[k][j]);


    vector<lli> dist(n,1e9);
    dist[s] = -earn[s];

    for(int k=0; k<=n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<v[i].size(); j++){
                int next = v[i][j].fst;
                lli cost = (lli)v[i][j].snd - earn[next];

                if(dist[i] != 1e9 && dist[next] > dist[i]+cost){
                    dist[next] = dist[i] + cost;
                    if(k == n && cango[next][e]) return cout << "Gee",0;
                }
            }
        }
    }

    if(!cango[s][e]) cout << "gg";
    else cout << -dist[e];
}
