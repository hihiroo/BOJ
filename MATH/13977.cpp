//이항계수와 쿼리
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back


lli mod = 1000000007, dp[4000001];
lli fast_pow(lli a, lli b){
    if(b == 0) return 1;
    if(b % 2) return (a*fast_pow(a,b-1))%mod;
    lli tmp = fast_pow(a,b/2);
    return (tmp*tmp)%mod;
}

int main(){
    dp[1] = 1;
    for(lli i=2; i<=4000000; i++)
        dp[i] = (dp[i-1]*i) % mod;

    int m,n,k;
    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%d%d",&n,&k);
        if(k == 0 || n == k){
            printf("1\n");
            continue;
        }
        lli ans = dp[n]*fast_pow((dp[k]*dp[n-k])%mod,mod-2);
        printf("%lld\n",ans%mod);
    }
}

