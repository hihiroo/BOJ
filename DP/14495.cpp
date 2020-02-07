// 피보나치 비스무리한 수열
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int


lli dp[117]={1,1,1,1};
lli f(int n){
    if(dp[n]) return dp[n];
    dp[n] = f(n-1) + f(n-3);
    return dp[n];
}
int main(){
   int n;
   cin>>n;
   printf("%lld",f(n));
}
