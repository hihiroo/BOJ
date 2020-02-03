//팀 연습
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


lli mod = 1000000007, dp[100005][10][2][2], k;

lli f(int l, int a, bool b, bool c){
    if(l == 0){
        if((!k || a % k == 0) && c) return 1;
        else return 0;
    }
    lli &ret = dp[l][a][b][c];
    if(ret != -1) return ret;

    ret = 0;
    if(k) ret = f(l-1,(a+1)%k,0,c); //l번째 문제를 a가 품
    if(!b) ret = (ret + f(l-1,a,1,c)) % mod;
    ret += f(l-1,a,0,1);
    ret %= mod;
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n>>k;
    cout<<f(n,0,0,0);
}
