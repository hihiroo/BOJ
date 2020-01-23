//피보나치 수의 합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli mod = 1000000000;

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
    else{
        matrix temp = fast_pow(n,k/2);
        return gop(temp,temp);
    }
}

matrix sum(lli k, matrix n){
    if(k == 1) return n;
    matrix ret, a;
    if(k % 2){
        ret = sum(k-1,n);
        a = fast_pow(n,k);
    }
    else{
        ret = sum(k/2,n);
        a = gop(ret,fast_pow(n,k/2));
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i][j] += a[i][j];
            ret[i][j] %= mod;
        }
    }
    return ret;
}
int fibo_sum[5] = {0,1,2,3,5};

int main(){
    lli n,m;
    cin>>n>>m;
    matrix dp(2);
    dp[0].pb(1), dp[0].pb(1);
    dp[1].pb(1), dp[1].pb(0);

    lli a = fibo_sum[2], b = fibo_sum[2], ans;
    matrix x;
    if(m < 3) a = fibo_sum[m];
    else{
        x = sum(m-2,dp);
        a += (x[0][0]+x[0][1])%mod;
    }
    if(n-1 < 3) b = fibo_sum[n-1];
    else{
        x = sum(n-3,dp);
        b += (x[0][0]+x[0][1])%mod;
    }
    ans = (a-b+mod)%mod;
    cout<<ans;
}

