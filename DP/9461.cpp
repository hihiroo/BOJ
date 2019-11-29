//파도반 수열

#include <bits/stdc++.h>
using namespace std;
#define lli long long

lli dp[105] = {0,1,1,1,2,2,3,4,5,7,9};

lli f(lli n){
    if(dp[n]) return dp[n];
    dp[n] = f(n-1) + f(n-5);
    return dp[n];
}
int main(){
    lli t;
    cin>>t;
    for(; t>0; t--){
        lli n;
        cin>>n;
        printf("%lld\n",f(n));
    }  
    return 0; 
}