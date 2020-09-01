//서로소 
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> p, v;

void init(){
    vector<int> chk(40000);
    for(int i=2; i<40000; i++){
        if(chk[i]) continue;
        p.pb(i);
        for(int j=2; i*j<40000; j++)
            chk[i*j] = 1;
    }
}

lli calc(lli a){
    lli ans = a;

    for(int i=1; i<(1<<v.size()); i++){
        lli gop = 1, cnt = 0;
        for(int j=0; j<v.size(); j++){
            if(i & (1<<j)){
                cnt++;
                gop *= v[j];
            }
        }

        if(cnt%2) ans -= a/gop;
        else ans += a/gop;
    }
    return ans;
}

lli solve(lli a, lli b, lli n){
    v.clear(); // n의 소인수

    lli k = n;
    for(int i=0; i<p.size() && p[i]<=n; i++){
        if(k%p[i] != 0) continue;

        v.pb(p[i]);
        while(k>0 && k%p[i]==0) k/=p[i];
    }
    if(k != 1) v.pb(k);

    return calc(b)-calc(a-1);
}

int main(){
    int t;
    cin >> t;

    init();

    for(int i=1; i<=t; i++){
        lli a,b,n;
        cin >> a >> b >> n;
        cout << "Case #" << i << ": ";
        cout << solve(a,b,n) << '\n';
    }
}
