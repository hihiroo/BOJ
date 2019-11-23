#include <bits/stdc++.h>
using namespace std;
#define lli long long


lli dp[105][105][2], n;

lli f(lli l, lli num, lli k){
    if(k < 0) return 0;
    if(l == 1){
        if(k == 0) return 1;
        else return 0;
    }
    if(dp[l][k][num] != -1) return dp[l][k][num];

    dp[l][k][num] = 0;
    if(num == 0)
        dp[l][k][num] = f(l-1,0,k) + f(l-1,1,k);
    
    else
        dp[l][k][num] = f(l-1,0,k) + f(l-1,1,k-1);
    
    return dp[l][k][num];
}

int main(){
    memset(dp,-1,sizeof(dp));
    lli t,k;
    cin>>t;
    for(; t>0; t--){
        cin>>n>>k;
        cout<<f(n,0,k)+f(n,1,k)<<'\n';
    }
}