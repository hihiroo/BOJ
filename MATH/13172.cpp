// Σ
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

lli mod = 1e9+7;

lli pow(lli a, lli b){
    if(b == 0) return 1;
    if(b%2) return (a*pow(a,b-1))%mod;
    lli x = pow(a, b/2);
    return (x*x)%mod;
}

int main(){
    cinFast();

    int m;
    cin >> m;

    lli ans = 0;
    for(int i=0; i<m; i++){
        lli a, b;
        cin >> a >> b;

        ans += b*pow(a,mod-2);
        ans %= mod;
    }

    cout << ans;
}
