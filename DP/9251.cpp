//LCS
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
string a,b;

int f(int i,int j){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];


    if(a[i] == b[j]) dp[i][j] = 1 + f(i-1,j-1);
    else dp[i][j] = max(f(i-1,j), f(i,j-1));

    return dp[i][j];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    cout << f(a.size()-1,b.size()-1);
}
