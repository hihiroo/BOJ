//구간 나누기
#include <bits/stdc++.h>
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n,m,arr[105],dp[105][55];

int f(int idx, int g){
    if(g == 0) return 0;
    if(idx >= n+1) return -1e7;
    if(dp[idx][g] != -1) return dp[idx][g];

    dp[idx][g] = f(idx+1,g);

    int sum = 0;
    for(int i=idx; i<=n; i++){
        sum += arr[i];
        dp[idx][g] = max(dp[idx][g],f(i+2,g-1)+sum);
    }

    return dp[idx][g];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> arr[i];

    cout << f(1,m);
}
