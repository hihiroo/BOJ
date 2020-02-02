//수강과목
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n,k,dp[10005][1005], I[1005], T[1005];

int f(int time, int l){
    if(l == 0) return 0;
    if(dp[time][l]) return dp[time][l];

    if(time-T[l] >= 0)
        dp[time][l] = I[l] + f(time-T[l],l-1);
    dp[time][l] = max(dp[time][l],f(time,l-1));

    return dp[time][l];
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=k; i++) cin>>I[i]>>T[i];
    cout<<f(n,k);
}
