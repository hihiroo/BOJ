//궁금한 민호
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dist[25][25], ans[25][25];

int main(){
    int n, sum = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> dist[i][j];
            ans[i][j] = dist[i][j];
            sum += dist[i][j];
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(k == i || k == j || ans[i][j] == 0) continue;

                if(dist[i][j] == dist[i][k] + dist[k][j])
                    sum -= dist[i][j], ans[i][j] = 0;
                else if(dist[i][j] > dist[i][k] + dist[k][j])
                    return cout << -1,0;
            }
        }
    }

   cout << sum/2;

}
