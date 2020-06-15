//RGB거리2
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int dp[3][1005][3], cost[1005][3], n;

int f(int color1, int idx, int color){
    if(idx == n){
        if(color == color1) return 1e6;
        else return cost[idx][color];
    }
    int &ret = dp[color1][idx][color];
    if(ret != -1) return ret;

    ret = 1e6;
    for(int i=0; i<3; i++)
        if(color != i)
            ret = min(ret,f(color1,idx+1,i)+cost[idx][color]);

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i=1; i<=n; i++)
        scanf("%d%d%d",&cost[i][0],&cost[i][1],&cost[i][2]);

    int ans = 1e6;
    ans = min(ans,f(0,1,0));
    ans = min(ans,min(f(1,1,1),f(2,1,2)));

    cout << ans;
}
