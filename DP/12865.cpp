//평범한 배낭
#include <bits/stdc++.h>
using namespace std;

int dp[105][100005], w[105], v[105];

int f(int i, int k){
    if(i == 0) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    if(w[i] <= k)
        dp[i][k] = v[i] + f(i-1,k-w[i]);
    dp[i][k] = max(dp[i][k], f(i-1,k));

    return dp[i][k];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        scanf("%d%d",&w[i],&v[i]);

    cout << f(n,k);
}
