//회장뽑기
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dist[55][55];

int main(){
    fill(&dist[0][0],&dist[51][51],54);

    int n;
    cin >> n;
    while(1){
        int a,b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        dist[a][b] = 1, dist[b][a] = 1;
        dist[a][a] = 0, dist[b][b] = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<int> > ans(55);
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            cnt = max(cnt,dist[i][j]);
        }
        ans[cnt].pb(i);
    }

    for(int i=0; i<=n; i++){
        if(ans[i].size() != 0){
            cout << i << " " << ans[i].size() << '\n';
            for(int j=0; j<ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            return 0;
        }
    }
}
