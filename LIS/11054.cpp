// 가장 긴 바이토닉 부분 수열

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
int arr[1000],n,dp[1000],dp2[1000];
int f(int idx){
    if(dp[idx]) return dp[idx];
    for(int i=idx-1; i>=0; i--){
        if(arr[idx] > arr[i]){
            dp[idx] = max(dp[idx],1+f(i));
        }
    }
    return dp[idx];
}
int f2(int idx){
    if(dp2[idx]) return dp2[idx];
    for(int i=idx+1; i<n; i++){
        if(arr[idx] > arr[i]){
            dp2[idx] = max(dp2[idx],1+f2(i));
        }
    }
    return dp2[idx];
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++) f(i),f2(i);
    int t = 0;
    for(int i=0; i<n; i++){
        t = max(f(i)+f2(i)+1,t);
    }
    printf("%d",t);
}



