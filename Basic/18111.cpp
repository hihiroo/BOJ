//마인크래프트
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int arr[505][505];
int main(){
    int n,m,b;
    cin>>n>>m>>b;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];
            

    int ans = 10000000, ansh;
    for(int h=256; h>=0; h--){
        int cnt = b, time = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j] < h){
                    time += h-arr[i][j];
                    cnt -= h-arr[i][j];
                }
                else if(arr[i][j] > h){
                    time += 2*(arr[i][j]-h);
                    cnt += arr[i][j]-h;
                }
            }
        }
        if(cnt < 0) continue;
        if(ans > time){
            ans = time;
            ansh = h;
        }
    }
    cout<<ans<<" "<<ansh;
}
