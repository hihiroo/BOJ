//무한 수열
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


map<lli,lli> dp;
int p,q;

lli f(lli n){
    if(dp[n]) return dp[n];
    dp[n] = f(n/p) + f(n/q);
    return dp[n];
}

int main(){
    lli n;
    dp[0] = 1;
    cin>>n>>p>>q;
    cout<<f(n);
}
