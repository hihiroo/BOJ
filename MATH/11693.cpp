//n^m의 약수의 합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back


bool chk[100000];
vector<lli> v;
lli mod = 1000000007;

lli fast_gop(lli a, lli b){
    if(b == 0) return 1;
    if(b % 2) return (fast_gop(a,b-1)*a)%mod;
    lli tmp = fast_gop(a,b/2);
    return (tmp*tmp)%mod;
}

lli sum(lli a, lli n){
    if(n == 1) return a;
    if(n % 2) return (fast_gop(a,n)+sum(a,n-1))%mod;
    lli tmp = sum(a,n/2);
    return (tmp+tmp*fast_gop(a,n/2))%mod;
}

int main(){
    for(lli i=2; i<100000; i++){
        if(chk[i]) continue;
        v.pb(i);
        for(lli j=2; i*j<100000; j++)
            chk[i*j] = 1;
    }

    lli n,m,ans=1;
    cin>>n>>m;
    lli k = n;
    if(m == 0 || n == 1) return cout<<1,0;
    for(lli i=0; v[i]*v[i]<=n; i++){
        if(k % v[i]) continue;
        lli cnt = 0, a = 0;
        while(k%v[i] == 0){//소인수가 몇 제곱인지
            k /= v[i];
            a++;
        }
        cnt = sum(v[i],a*m);
        ans += (ans*cnt)%mod;
        ans %= mod;
    }
    if(k != 1){
        lli cnt = sum(k,m);
        ans += (ans*cnt)%mod;
        ans %= mod;
    }
    cout<<ans;
}
