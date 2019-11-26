//1학년

#include <bits/stdc++.h>
using namespace std;
#define lli long long


lli arr[105], n, dp[1005][105];

lli f(lli sum, lli idx){
    if(sum > 20 || sum < 0) return 0;
    if(idx == 1){
        if(sum == arr[1]) return 1;
        else return 0;
    } 
    lli &res = dp[sum][idx];
    if(res != -1) return res;
    
    res = f(sum-arr[idx],idx-1) + f(sum+arr[idx],idx-1);
    return res;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(lli i=1; i<=n; i++) cin>>arr[i];
    cout<<f(arr[n],n-1);
}