//홀수번째 피보나치 수의 합
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
    else{
        matrix temp = fast_pow(n,k/2);
        return gop(temp,temp);
    }
}

matrix sum(lli k, matrix n){
    if(k == 1) return n;
    matrix ret, a;
    if((k+1)/2 % 2){
        ret = sum(k-2,n);
        a = fast_pow(n,k);
    }
    else{
        ret = sum((k+1)/2-1,n);
        a = gop(ret,fast_pow(n,(k+1)/2));
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i][j] += a[i][j];
            ret[i][j] %= mod;
        }
    }
    return ret;
}


int main(){
    lli n;
    cin>>n;
    matrix dp(2);
    dp[0].pb(1), dp[0].pb(1);
    dp[1].pb(1), dp[1].pb(0);
    
    if(n%2 == 0) n--;
    if(n == 1) return cout<<"1",0;
    dp = sum(n-2,dp);
    cout<<(dp[0][0]+dp[0][1]+1)%mod;
}

