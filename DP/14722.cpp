//우유 도시
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dp[1005][1005][3], arr[1005][1005], n;

int f(int y, int x, int num){
    if(y < 1 || x < 1 || x > n || y > n) return 0;
    if(y == n && x == n) return arr[y][x] == num;
    int &ret = dp[y][x][num];
    if(ret != -1) return ret;

    int next = num;
    if(arr[y][x] == num) ret = 1, next = (num+1)%3;
    else ret = 0;

    ret += max(f(y+1,x,next), f(y,x+1,next));

    return dp[y][x][num];
}

int main(){
    memset(dp,-1,sizeof(dp));

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    cout << f(1,1,0);
}
