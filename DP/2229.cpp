//조 짜기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int dp[1005][1005], arr[1005];

int f(int s, int e){
    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    
    int min_ = 10000, max_ = 0;
    for(int i=s; i<=e; i++){
        min_ = min(min_,arr[i]);
        max_ = max(max_,arr[i]);
        dp[s][e] = max(dp[s][e],max_-min_+f(i+1,e));
    }
    return dp[s][e];
}

int main(){
    int N;
    cin>>N;
    memset(dp,-1,sizeof(dp));

    for(int i=1; i<=N; i++)
        cin>>arr[i];
    cout<<f(1,N);
}