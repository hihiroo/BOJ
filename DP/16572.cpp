// Pixel Triangle
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int dp[2005][2005], arr[2005][2005], ans;

int f(int y, int x){
    if(y < 1 || x < 1) return 0;

    int &ret = dp[y][x];
    if(ret != -1) return ret;

    ret = arr[y][x];
    ret = max(ret, max(f(y-1,x), f(y,x-1))-1);

    if(ret) ans++;
    return ret;
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));

    int n;
    cin >> n;

    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a][b] = max(arr[a][b],c);
    }

    f(2000,2000);
    cout << ans;
}
