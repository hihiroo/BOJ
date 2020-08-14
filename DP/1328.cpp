//고층 빌딩
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli mod = 1e9+7, dp[105][105][105],n,a,b;

lli f(lli len, lli l, lli r){
    if(l < 1 || r < 1) return 0;
    if(l+r-1 > len) return 0;
    if(len == l || len == r) return 1;
    if(dp[len][l][r] != -1) return dp[len][l][r];

    dp[len][l][r] = f(len-1,l-1,r) + f(len-1,l,r-1) + f(len-1,l,r)*(len-2);
    dp[len][l][r] %= mod;
    return dp[len][l][r];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> a >> b;
    cout << f(n,a,b);
}
