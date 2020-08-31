//배열과 gcd
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<lli> C(100005), v;
lli n, num;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

bool isPoss(){
    for(int i=1; i<n; i++)
        if(gcd(C[i-1],C[i]) != C[i]) return 0;
    return 1;
}

void init(){
    //소수 구하기
    vector<lli> chk(50000), p;
    for(lli i=2; i<=40000; i++){
        if(chk[i]) continue;
        p.pb(i);
        for(lli j=2; i*j<=40000; j++)
            chk[i*j] = 1;
    }

    //C[0]인수분해하기
    int k = C[0];
    for(int i=0; i<p.size()&&p[i]<k; i++){
        if(C[0]%p[i] != 0) continue;
        v.pb(p[i]);
        while(k > 0 && k%p[i] == 0) k /= p[i];
    }

    if(k != 1) v.pb(k);
    //13!이 6억정도니까 v의 사이즈는 최대 12
}

lli solve(){
    lli mod = 1e9+7, ans = 1;

    for(int i=1; i<n; i++){
        lli gap = C[i-1]/C[i];
        lli k = num/C[i];

        vector<lli> target;
        for(int j=0; j<v.size(); j++){
            if(v[j] > gap) break;
            if(gap%v[j] == 0) target.pb(v[j]);
        }

        //포함배제 비트가 1이면 교집합
        for(int j=1; j<(1<<target.size()); j++){
            lli cnt = 0, gop = 1;

            for(int x=0; x<target.size(); x++){
                if(j & (1<<x)){
                    cnt++;
                    gop *= target[x];
                }
            }

            if(cnt%2) k -= num/(gop*C[i]);
            else k += num/(gop*C[i]);
        }
        ans *= k, ans %= mod;
    }
    return ans;
}

int main(){
    cinFast();

    cin >> n >> num;
    for(int i=0; i<n; i++) cin >> C[i];

    if(!isPoss()) return cout << 0,0;

    init();
    cout << solve();
}
