//합분해

#include <bits/stdc++.h>
using namespace std;

#define lli long long

lli dp[205][205], mod = 1000000000, n, k;

lli f(lli sum, lli cnt){
    if(sum == 0 && cnt == 0) return 1;
    if(sum < 0 || cnt <= 0) return 0;
    if(dp[sum][cnt] != -1) return dp[sum][cnt]; 

    dp[sum][cnt] = 0;
    for(lli i=0; i<=sum; i++){
        dp[sum][cnt] += f(sum-i,cnt-1);
        dp[sum][cnt] %= mod;
    }
    return dp[sum][cnt];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    cout<<f(n,k);
}