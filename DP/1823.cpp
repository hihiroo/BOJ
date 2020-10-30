//수확
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli dp[2005][2005], arr[2005], n;

lli f(int s, int e){
    if(dp[s][e] != -1) return dp[s][e];
    if(s == e) return n*arr[s];

    lli k = (lli)((s-1)+(n-e)+1);
    dp[s][e] = max(arr[s]*k+f(s+1,e), arr[e]*k+f(s,e-1));

    return dp[s][e];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];
    cout << f(1,n);
}
