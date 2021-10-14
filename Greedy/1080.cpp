// 행렬
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    int n, m;
    cin >> n >> m;

    int A[n][m], B[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) scanf("%1d",&A[i][j]);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&B[i][j]);
            B[i][j] ^= A[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(B[i][j] == 1){
                for(int y=0; y<3; y++){
                    for(int x=0; x<3; x++){
                        if(i+y == n || j+x == m) return cout << -1, 0;
                        B[i+y][j+x] ^= 1;
                    }
                }
                ans++;
            }
        }
    }
    cout << ans;
}
