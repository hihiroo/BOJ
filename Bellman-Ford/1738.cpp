//골목길
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<pair<int,int> > > v(105);

int main(){
    cinFast();
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        v[a].pb(mp(b,w));
    }

    vector<int> dist(n+1,-1e8), pre(n+1);
    dist[1] = 0, pre[1] = -1;

    for(int i=0; i<2*n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<v[j].size(); k++){
                int next = v[j][k].fst;
                int cost = v[j][k].snd;

                if(dist[j] != -1e8 && dist[next] < dist[j]+cost){
                    dist[next] = dist[j] + cost;
                    if(i >= n-1) dist[next] = 1e8;
                    pre[next] = j;
                }
            }
        }
    }
    if(dist[n] >= 1e8) return cout << -1,0;


    vector<int> ans;
    for(int i=n; i!=-1; i=pre[i]) ans.pb(i);

    for(int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";
}
