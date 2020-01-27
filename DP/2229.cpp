//조 짜기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dp[1005], arr[1005],N;

int f(int s){
    if(s > N) return 0;
    if(dp[s] != -1) return dp[s];
    
    int min_ = 10000, max_ = 0;
    for(int i=s; i<=N; i++){
        min_ = min(min_,arr[i]);
        max_ = max(max_,arr[i]);
        dp[s] = max(dp[s],max_-min_+f(i+1));
    }
    return dp[s];
}

int main(){
    cin>>N;
    memset(dp,-1,sizeof(dp));

    for(int i=1; i<=N; i++) cin>>arr[i];
    cout<<f(1);
}