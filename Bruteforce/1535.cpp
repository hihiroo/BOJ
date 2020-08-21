//안녕
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, ans = 0, m[25], p[25];

void f(int i, int cnt, int rem){
    if(rem <= 0) return;
    if(i == n){
        ans = max(ans, cnt);
        return;
    }
    f(i+1,cnt+p[i],rem-m[i]);
    f(i+1,cnt,rem);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> m[i];
    for(int i=0; i<n; i++) cin >> p[i];

    f(0,0,100);
    cout << ans;
}
