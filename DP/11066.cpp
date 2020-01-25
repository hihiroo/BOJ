//파일 합치기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dp[505][505], sum[505][505], k;

int f(int s, int e){
    if(s == e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    dp[s][e] = 90000000;
    for(int i=s; i<e; i++)
        dp[s][e] = min(dp[s][e],f(s,i)+f(i+1,e)+sum[s][i]+sum[i+1][e]);

    return dp[s][e];
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        cin>>k;
        memset(dp,-1,sizeof(dp));
        memset(sum,0,sizeof(sum));

        for(int i=1; i<=k; i++){
            scanf("%d",&sum[i][i]);
            sum[1][i] = sum[1][i-1]+sum[i][i];
        }

        for(int i=1; i<=k; i++)
            for(int j=i; j<=k; j++)
                sum[i][j] = sum[1][j] - sum[1][i-1];

        cout<<f(1,k)<<'\n';
    }
}
