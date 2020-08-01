//1 2 3 더하기 5
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

lli mod = 1e9+9, dp[100005][4];

lli f(int num, int pre){
    if(num < 0) return 0;
    if(num == 0) return 1;
    if(dp[num][pre] != -1) return dp[num][pre];

    dp[num][pre] = 0;
    if(pre != 1) dp[num][pre] += f(num-1,1);
    if(pre != 2) dp[num][pre] += f(num-2,2);
    if(pre != 3) dp[num][pre] += f(num-3,3);
    dp[num][pre] %= mod;

    return dp[num][pre];
}

int main(){
    memset(dp,-1,sizeof(dp));

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << f(n,0) << '\n';
    }
}
