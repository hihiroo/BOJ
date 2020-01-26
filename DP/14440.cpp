//정수 수열
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef vector<vector<int> > matrix;
int mod = 100, y, x, a0, a1;

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

matrix fast_pow(matrix  a, int b){
    if(b == 1) return a;
    if(b % 2) return gop(a,fast_pow(a,b-1));
    matrix temp = fast_pow(a,b/2);
    return gop(temp,temp);
}

int main(){
    int n;
    cin>>x>>y>>a0>>a1>>n;
    if(n == 0) return cout<<a0,0;
    else if(n == 1) return cout<<a1,0;

    vector<vector<int> > dp(2);
    dp[0].pb(x), dp[0].pb(y);
    dp[1].pb(1), dp[1].pb(0);
    dp = fast_pow(dp,n-1);
    int ans = (dp[0][0]*a1 + dp[0][1]*a0)%mod;
    if(ans == 0) cout<<"00"; 
    else if(ans < 10) cout<<"0"<<ans;
    else cout<<ans;
}
