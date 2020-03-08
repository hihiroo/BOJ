//벼락치기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dp[105][10005], K[105], S[105];

int f(int num, int time){
    if(dp[num][time]) return dp[num][time];

    for(int i=num-1; i>0; i--){
        if(time >= K[i])
            dp[num][time] = max(dp[num][time],S[i]+f(i,time-K[i]));
    }

    return dp[num][time];
}

int main(){
    int n,t;
    cin>>n>>t;

    for(int i=1; i<=n; i++) cin>>K[i]>>S[i];

    cout<<f(n+1,t);
}


