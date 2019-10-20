// 괄호

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

lli n,k,C[1000005]={1}, mod=1000000007;

lli fast_gop(lli a, lli b){ //빠른제곱
    if(b == 0) return 1;
    if(b%2) return (a*fast_gop(a,b-1))%mod;
    lli x = fast_gop(a,b/2);
    return (x*x)%mod;
}

int main(){
    cin>>n>>k;

    //카탈란 수 C(ai)구하기
    lli bunja = 1, bunmo = 1;
    for(lli i=0; i<n/2; i++){
        bunja *= ((2*i+1)*(2*i+2))%mod;
        bunmo *= ((i+1)*(i+2))%mod;
        bunja %= mod, bunmo %= mod;

        C[i+1] = (bunja * fast_gop(bunmo,mod-2))%mod;
    }

    //경우의 수 S(n)구하기
    lli cur = 1;
    for(lli i=0; i<n; i++){
        if(i%2 == 0)
            cur = ((k+1)*cur)%mod + mod - (fast_gop(k,i/2)*C[i/2])%mod;
        else cur = (k+1)*cur;
        cur %= mod;
    }
    cout<<cur;
}
