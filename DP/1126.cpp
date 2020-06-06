//같은 탑
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int arr[55], dp[55][500005];

int f(int idx, int gap){
    if(idx == 0) return 0;
    int &ret = dp[idx][gap];
    if(ret != -1) return ret;

    ret = f(idx-1,gap);
    ret = max(ret,f(idx-1,gap+arr[idx]));

    int tmp;
    if(arr[idx] < gap){
        tmp = f(idx-1,gap-arr[idx]);
        if(tmp) ret = max(ret,tmp+arr[idx]);
    }
    else{
        tmp = f(idx-1,arr[idx]-gap);
        if(tmp) ret = max(ret,tmp+gap);
    }
    if(arr[idx] == gap) ret = max(ret,arr[idx]);

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);

    int ans = f(n,0);
    if(ans == 0) cout << -1;
    else cout << ans;
}
