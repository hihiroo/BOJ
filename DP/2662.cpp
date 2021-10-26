// 기업투자
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int dp[305][25], profit[305][25], howmuch[305][25];

int f(int remain, int idx){
    if(remain == 0 || idx == -1) return 0;
    if(dp[remain][idx] != -1) return dp[remain][idx];

    int &res = dp[remain][idx];

    int best = 0;
    for(int i=0; i<=remain; i++){
        int temp = profit[i][idx]+f(remain-i, idx-1);
        if(res < temp) res = temp, best = i;
    }

    howmuch[remain][idx] = best;
    return res;
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));

    int n, m;
    cin >> n >> m;

    for(int i=1, a; i<=n; i++){
        cin >> a;
        for(int j=0; j<m; j++) cin >> profit[i][j];
    }

    cout << f(n,m-1) << '\n';

    vector<int> ans(m);
    for(int i=m-1, remain=n; i>=0; i--){
        ans[i] = (howmuch[remain][i]);
        remain -= ans[i];
    }

    for(int i=0; i<m; i++) cout << ans[i] << " ";
}
