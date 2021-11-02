// 1, 2, 3 더하기 6
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

lli dp[100005], mod = 1e9+9;

lli f(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (f(n-1) + f(n-2) + f(n-3))%mod;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        lli ans = 0;
        if(n%2 == 0) ans += f(n/2);
        if((n-1)%2 == 0) ans += f((n-1)/2);
        if((n-2)%2 == 0) ans += f((n-2)/2);
        if((n-3)%2 == 0) ans += f((n-3)/2);
        cout << ans % mod << '\n';
    }
}
