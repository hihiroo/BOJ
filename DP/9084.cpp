// 동전

#include <bits/stdc++.h>
using namespace std;

int dp[10005][25], n, m, arr[25];

int f(int sum, int k){
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(k == 0) return 0;
    if(dp[sum][k] != -1) return dp[sum][k];

    dp[sum][k] = 0;
    for(int i=0; sum-arr[k]*i>=0; i++)
        dp[sum][k] += f(sum-arr[k]*i,k-1);
    
    return dp[sum][k];
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);

        cin>>m;
        cout<<f(m,n)<<'\n';
    }
}