//캔디 분배
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef pair<lli,pair<lli,lli> > p3;
lli k,c;
 p3 exGcd(lli a, lli b){
    if(b == 0) return mp(a,mp(1,0));
    p3 tmp = exGcd(b,a%b);
    lli x = tmp.snd.fst, y = tmp.snd.snd;
    return mp(tmp.fst,mp(y%k,(x-(a/b)*y)%k));
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        cin>>k>>c;
        p3 ret = exGcd(c,k);
        if((k==1 && c != 1) || ret.fst != 1) cout<<"IMPOSSIBLE\n";
        else{
            lli ans = ret.snd.fst;
            while(c*ans <= k) ans += k;
            if(ans > 1000000000)
                cout<<"IMPOSSIBLE\n";
            else cout<<ans<<'\n';
        }
    }
}
