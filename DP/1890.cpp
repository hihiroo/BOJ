//점프
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int arr[105][105], dp[105][105], n;

lli f(int y, int x){
    if(y == n && x == n) return 1;
    if(y < 1 || x < 1 || y > n || x > n) return 0;
    if(arr[y][x] == 0) return 0;
    if(dp[y][x] != -1) return dp[y][x];

    dp[y][x] = f(y+arr[y][x],x);
    dp[y][x] += f(y,x+arr[y][x]);

    return dp[y][x];
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    cout << f(1,1);
}
