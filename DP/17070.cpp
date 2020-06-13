//파이프 옮기기 1
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;


int n, arr[20][20], dp[3][20][20];
// dir == 0 -, 1 -> \, 2 -> |

bool safe(int y, int x){
    return y>=1&&y<=n && x>=1&&x<=n && !arr[y][x];
}

int f(int dir, int y, int x){
    if(y == n && x == n) return 1;
    int &ret = dp[dir][y][x];
    if(ret != -1) return ret;

    ret = 0;
    if(safe(y+1,x+1) && safe(y+1,x) && safe(y,x+1)) ret += f(1,y+1,x+1);
    if(dir <= 1 && safe(y,x+1)) ret += f(0,y,x+1);
    if(dir >= 1 && safe(y+1,x)) ret += f(2,y+1,x);

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    cout << f(0,1,2);
}
