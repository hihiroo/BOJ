//역원구하기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef pair<lli,pair<lli,lli> > p3;
lli n;
 p3 exGcd(lli a, lli b){
    if(b == 0) return mp(a,mp(1,0));
    p3 tmp = exGcd(b,a%b);
    lli x = tmp.snd.fst, y = tmp.snd.snd;
    return mp(tmp.fst,mp(y%n,(x-(a/b)*y)%n));
}

int main(){
    lli a;
    cin>>n>>a;
    cout<<n-a<<" ";
    p3 ret = exGcd(a,n);
    if(ret.fst != 1) return cout<<-1,0;
    while(ret.snd.fst < 0) ret.snd.fst += n;
    cout<<ret.snd.fst % n;
}
