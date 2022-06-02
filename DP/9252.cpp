// LCS 2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

int dp[1005][1005];
string a,b;
pair<int,int> t[1005][1005];

int f(int ai, int bi){
    if(ai == a.size() || bi == b.size()) return 0;
    if(dp[ai][bi] != -1) return dp[ai][bi];

    dp[ai][bi] = 0;

    if(a[ai] == b[bi]){
        t[ai][bi] = mp(ai+1, bi+1);
        dp[ai][bi] = 1 + f(ai+1,bi+1);
    }
    else{
        int lf = f(ai+1, bi), rf = f(ai, bi+1);

        if(lf > rf) t[ai][bi] = mp(ai+1,bi);
        else t[ai][bi] = mp(ai,bi+1);
        dp[ai][bi] = max(lf, rf);
    }
    return dp[ai][bi];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> a >> b;
    cout << f(0,0) << '\n';

    int ai = 0, bi = 0;
    while(ai < a.size() && bi < b.size()){
        if(a[ai] == b[bi]) cout << a[ai];
        pair<int,int> nxt = t[ai][bi];
        ai = nxt.fst, bi = nxt.snd;
    }
}
