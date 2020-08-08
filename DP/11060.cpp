//점프 점프
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[1005], arr[1005], n;

int f(int idx){
    if(idx == n-1) return 0;
    if(dp[idx] != -1) return dp[idx];

    dp[idx] = 1e7;
    for(int i=1; i<=arr[idx]; i++)
        dp[idx] = min(f(idx+i)+1,dp[idx]);

    return dp[idx];
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    if(n == 1) return cout << 0,0;

    int ans = f(0);
    if(ans >= 1e7) return cout << -1,0;
    else cout << ans;
}
