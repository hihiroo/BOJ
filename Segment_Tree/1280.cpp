//나무 심기
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli n, tree[200005], cnt[200005], mod = 1e9+7;

void update(lli i){
    lli val = i;

    while(i <= 200001){
        tree[i] += val, cnt[i]++;
        tree[i] %= mod, cnt[i] %= mod;
        i += (i & -i);
    }
}

pair<lli,lli> sum(lli i){
    pair<lli,lli> ret = mp(0,0);
    while(i > 0){
        ret.fst += tree[i], ret.snd += cnt[i];
        ret.fst %= mod, ret.snd %= mod;
        i -= (i & -i);
    }
    return ret;
}

int main(){
    cinFast();
    cin >> n;

    lli ans = 1, a;
    cin >> a;
    update(++a);

    for(int i=1; i<n; i++){
        cin >> a;

        pair<lli,lli> l = sum(++a), r = sum(200001);
        lli k = l.snd*a - l.fst + (r.fst-l.fst)-(r.snd-l.snd)*a;
        k = (k%mod+mod)%mod;
        ans *= k, ans %= mod;

        update(a);
    }
    cout << ans;
}
