//무한 수열2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


unordered_map<lli,lli> dp;
int p,q,x,y;

lli f(lli n){
    if(n <= 0) return 1;
    if(dp.find(n) != dp.end()) return dp[n];
    dp[n] = f(n/p-x) + f(n/q-y);
    return dp[n];
}

int main(){
    lli n;
    cin>>n>>p>>q>>x>>y;
    cout<<f(n);
}
