//동물원
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[100005][3], n, mod = 9901;

int f(int r, int pre){
    if(r == n) return 1;
    if(dp[r][pre] != -1) return dp[r][pre];

    dp[r][pre] = f(r+1,0);
    if(pre != 1) dp[r][pre] += f(r+1,1);
    if(pre != 2) dp[r][pre] += f(r+1,2);
    dp[r][pre] %= mod;

    return dp[r][pre];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cout << f(0,0);
}
