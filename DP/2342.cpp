//Dance Dance Revolution
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int dp[100005][5][5];
vector<int> arr;

int moveF(int cur, int next){
    if(cur == 0) return 2;
    if(cur == next) return 1;
    if(cur % 2 == next % 2) return 4;
    return 3;
}

int f(int p, int l, int r){
    if(p == arr.size()) return 0;
    int &ret = dp[p][l][r];
    if(ret != -1) return ret;

    //왼쪽 발을 움직일 때
    ret = f(p+1,arr[p],r) + moveF(l,arr[p]);
    //오른쪽 발을 움직일 때
    ret = min(ret,f(p+1,l,arr[p])+moveF(r,arr[p]));

    return ret;
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));

    while(1){
        int n;
        cin >> n;
        if(!n) break;
        arr.pb(n);
    }
    cout << f(0,0,0);
}
