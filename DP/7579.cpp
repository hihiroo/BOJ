//앱
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dp[105][10005],n,m;
int byte[105], cost[105];

int f(int num, int c){
    if(dp[num][c]) return dp[num][c];

    for(int i=num-1; i>0; i--){
        if(c >= cost[i])
            dp[num][c] = max(dp[num][c],byte[i]+f(i,c-cost[i]));
    }

    return dp[num][c];
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        scanf("%d",&byte[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&cost[i]);

    int ans = 10000;
    for(int i=0; i<=10000; i++){
        int res = f(n+1,i);
        if(dp[n+1][i] >= m) ans = min(ans,i);
    }
    cout<<ans;
}
