//습격자 초라기
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, w, arr[2][10005], dp[10005][4][4];

int f(int vtx, int cur, int last){
    if(vtx == n-1){
        if(cur == 3) return 0;
        if(cur == 0 && arr[0][vtx]+arr[1][vtx] > w) return 2;
        return 1;
    }
    int &ret = dp[vtx][cur][last];
    if(ret != -1) return ret;

    ret = 1e8;
    if(cur == 0 && arr[0][vtx]+arr[1][vtx]<= w)
        ret = min(ret,1+f(vtx+1,vtx==n-2?last:0,last));

    for(int i=0; i<2; i++){
        int wi = arr[0][vtx];

        if(i == 1) wi += arr[0][vtx+1];
        if(wi > w || (i==1 && vtx==n-2 && (last&1))) continue;

        for(int j=0; j<2; j++){
            int wj = arr[1][vtx], poss = 0, next = 0;
            if(vtx == n-2) next = last;

            if(j == 1) wj += arr[1][vtx+1];
            if(wj > w || (j==1 && vtx==n-2 && (last&2))) continue;

            if(!(cur&1)){
                poss++;
                if(i == 1) next += 1;
            }
            if(!(cur&2)){
                poss++;
                if(j == 1) next += 2;
            }
            ret = min(ret,poss+f(vtx+1,next,last));
        }
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> w;

        for(int i=0; i<n; i++) cin >> arr[0][i];
        for(int i=0; i<n; i++) cin >> arr[1][i];

        memset(dp,-1,sizeof(dp));

        int ans = f(0,0,0);
        if(arr[0][n-1]+arr[0][0] <= w) ans = min(ans,1+f(0,1,1));
        if(arr[1][n-1]+arr[1][0] <= w) ans = min(ans,1+f(0,2,2));
        if(arr[0][n-1]+arr[0][0] <= w && arr[1][n-1]+arr[1][0]<= w)
            ans = min(ans,2+f(0,3,3));

        cout << ans << '\n';
    }
}
