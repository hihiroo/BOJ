// 정수

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

lli dp[20][1<<10][2];
int k;
string n;

int countbit(int t){
    int ret = 0;
    for(int i=1; i<=t; i*=2) if(t&i) ret++;
    return ret;
}

lli pos(int l, int t){
    lli ans = 1;
    for(int i=0; i<n.size()-l-1; i++) ans *= 10;
    return (lli)t*ans;
}

lli f(int l, int cur, bool bigger){
    if(countbit(cur) > k) return 1e18;
    if(l == n.size()){
        if(countbit(cur) == k) return 0;
        else return 1e18;
    }
    lli &ret = dp[l][cur][bigger];
    if(ret != -1) return ret;

    ret = 1e18;
    for(int i=0; i<=9; i++){
        if(!bigger && i<(n[l]-'0')) continue;
        if(n[l]-'0' == i) ret = min(ret,f(l+1,cur|(1<<i),bigger)+pos(l,i));
        else ret = min(ret, f(l+1,cur|(1<<i),1) + pos(l,i));
    }

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));

    cin >> n >> k;

    if(n.size() < k){
        cout << "10";
        for(int i=2; i<k; i++) cout << i;
        return 0;
    }

    lli ans = pos(0,(n[0]-'0')) + f(1,1<<(n[0]-'0'),0);
    if(n[0]=='9') ans = min(ans, pos(0,10)+f(1,3,1));
    else ans = min(ans,pos(0,n[0]-'0'+1) + f(1,1<<(n[0]-'0'+1),1));
    cout << ans;
}
