//이동하기
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[1005][1005], arr[1005][1005];

int f(int n, int m){
    if(n < 1 || m < 1) return 0;
    if(n == 1 && m == 1) return arr[n][m];
    if(dp[n][m] != -1) return dp[n][m];

    dp[n][m] = arr[n][m];
    dp[n][m] += max(f(n-1,m),max(f(n,m-1),f(n-1,m-1)));
    return dp[n][m];
}

int main(){
    memset(dp,-1,sizeof(dp));

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> arr[i][j];

    cout << f(n,m);
}
