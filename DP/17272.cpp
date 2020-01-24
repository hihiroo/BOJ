//리그 오브 레전설(large)
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

int M;
lli N, mod = 1000000007;
typedef vector<vector<lli> > matrix;

matrix gop(matrix a, matrix b){
    matrix ret(M);
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            ret[i].pb(0);
            for(int k=0; k<M; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix v, lli k){
    if(k == 1) return v;
    if(k % 2) return gop(v,fast_pow(v,k-1));
    matrix temp = fast_pow(v,k/2);
    return gop(temp,temp);
}

int main(){
    cin>>N>>M;
    if(N < M) return cout<<"1",0;
    matrix dp(M);
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(i-1 == j) dp[i].pb(1);
            else dp[i].pb(0);
        }
    }
    dp[0][0] = 1, dp[0][M-1] = 1;
    dp = fast_pow(dp,N-M+1);
    lli ans = 0;
    for(int i=0; i<M; i++){
        ans += dp[0][i];
        ans %= mod;
    }
    cout<<ans;
}

