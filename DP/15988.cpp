//1, 2, 3 더하기 3
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

lli mod = 1e9+9, dp[1000005] = {0, 1, 2, 4};

int main(){
    cinFast();
    for(int i=4; i<=1000000; i++)
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%mod;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}
