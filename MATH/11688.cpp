//최소공배수 찾기
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

lli gcd(lli a, lli b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    lli a,b,L;
    cin>>a>>b>>L;
    lli k = gcd(a,b);
    lli n = a*b/k; //a, b의 최소공배수
    if(L % n) return cout<<-1,0;
    lli z = L / n;
    for(lli i=1; i<=n; i++){
        if(n % i == 0 && gcd(n/i,z) == 1)
            return cout<<z*i,0;
    }
}
