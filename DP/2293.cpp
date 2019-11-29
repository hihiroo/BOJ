//동전1

#include <bits/stdc++.h>
using namespace std;


int dp[10005] = {1};
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++){
        int coin;
        scanf("%d",&coin);
        for(int j=coin; j<=k; j++)
            dp[j] += dp[j-coin];
    }
    printf("%d",dp[k]);
}