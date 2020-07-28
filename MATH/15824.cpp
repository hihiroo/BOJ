//너 봄에는 캡사이신이 맛있단다
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

lli mod = 1e9+7;

lli fast_pow(lli a, lli b){
    if(b == 0) return 1;
    if(b%2) return (fast_pow(a,b-1)*a)%mod;
    lli x = fast_pow(a,b/2);
    return (x*x)%mod;
}

int main(){
    int n;
    cin >> n;

    vector<lli> v;
    for(int i=0; i<n; i++){
        lli a;
        cin >> a;
        v.pb(a);
    }

    sort(v.begin(),v.begin()+n);

    lli sum = 0;
    for(int i=0; i<n; i++){
        lli lv = fast_pow(2,i);
        //v[i]가 제일 큰 경우 = v[i]포함, v[i+1]~제외 개수만큼
        sum += (lv-1)*v[i];
        sum %= mod;

        lv = fast_pow(2,v.size()-1-i);

        sum -= (lv-1)*v[i];
        sum = (sum + mod) % mod;
    }
    cout << sum;
}
