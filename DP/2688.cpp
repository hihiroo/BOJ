#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli dp[70][15], n;

lli f(lli l, lli num){
    if(num < 0 || num > 9) return 0;
    if(l == 1) return 1;
    if(dp[l][num] != -1)  return dp[l][num];
    dp[l][num] = 0;
    for(lli i=num; i>=0; i--)
        dp[l][num] += f(l-1,i);

    return dp[l][num];
}

int main(){
    memset(dp,-1,sizeof(dp));
    lli t;
    cin>>t;
    for(; t>0; t--){
        cin>>n;
        lli ans = 0;
        for(lli i=0; i<=9; i++) ans += f(n,i);
        cout<<ans<<'\n';
    }
}