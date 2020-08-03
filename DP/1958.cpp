//LCS3
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dp[105][105][105];
string a,b,c;

int f(int x, int y, int z){
    if(x < 0 || y < 0 || z < 0) return 0;
    if(dp[x][y][z] != -1) return dp[x][y][z];

    int &ret = dp[x][y][z];

    if(a[x] == b[y] && b[y] == c[z])
        ret = 1 + f(x-1,y-1,z-1);
    else{
        ret = f(x-1,y,z);
        ret = max(ret, f(x,y-1,z));
        ret = max(ret, f(x,y,z-1));
        ret = max(ret,f(x-1,y-1,z));
        ret = max(ret,f(x-1,y,z-1));
        ret = max(ret,f(x,y-1,z-1));
    }
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> a >> b >> c;
    cout << f(a.size()-1,b.size()-1,c.size()-1);
}
