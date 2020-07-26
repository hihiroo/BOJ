//N포커
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, mod = 10007, dp[13][53][2];

int f(int idx, int p, bool four){
    if(p <= 0) return p == 0 && four;
    if(idx == 13) return 0;
    int &ret = dp[idx][p][four];
    if(ret != -1) return ret;

    ret = f(idx+1,p,four);
    ret += f(idx+1,p-1,four)*4;
    ret += f(idx+1,p-2,four)*6;
    ret += f(idx+1,p-3,four)*4;
    ret += f(idx+1,p-4,1);
    ret %= mod;
    
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cout << f(0,n,0);
}


