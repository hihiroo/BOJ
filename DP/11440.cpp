//피보나치 수의 제곱의 합

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


lli mod = 1000000007;

typedef vector<vector<lli> > matrix;

matrix gop(matrix a, matrix b){
    matrix ret(2);
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i].pb(0);
            for(int k=0; k<2; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix n, lli k){
    if(k == 1) return n;
    if(k % 2) return gop(n,fast_pow(n,k-1));
    matrix temp = fast_pow(n,k/2);
    return gop(temp,temp);
}

matrix sum(lli k, matrix n){
    if(k == 1) return fast_pow(n,4*k-3);
    matrix a, b;
    if(k % 2 == 0){
        a = sum(k/2,n);
        b = gop(fast_pow(n,k*2),a);
    }
    else{
        a = sum(k-1,n);
        b = fast_pow(n,4*k-3);
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            a[i][j] += b[i][j];
            a[i][j] %= mod;
        }
    }
    return a;
}


int main(){
    lli n;
    cin>>n;
    matrix dp(2);
    dp[0].pb(1), dp[0].pb(1);
    dp[1].pb(1), dp[1].pb(0);
    if(n == 1) return cout<<1,0;

    if(n % 2){
        matrix a = fast_pow(dp,n-2);
        dp = sum((n-1)/2,dp);
        lli ans = (a[0][0]+a[0][1])%mod;
        ans = (ans*ans)%mod;
        ans += (dp[0][0]+dp[0][1])%mod;
        return cout<<ans%mod,0;
    }
    else dp = sum(n/2,dp);
    cout<<(dp[0][0]+dp[0][1])%mod;
}

