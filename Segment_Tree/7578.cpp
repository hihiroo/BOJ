//공장
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli n, tree[500005];

lli sum(lli i){
    lli ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(lli i){
    while(i <= n){
        tree[i] += 1;
        i += (i & -i);
    }
}

int main(){
    cinFast();
    cin >> n;

    map<lli,lli> arr;
    for(lli i=1; i<=n; i++){
        lli a;
        cin >> a;
        arr[a] = i;
    }

    lli ans = 0;
    for(lli i=1; i<=n; i++){
        lli a;
        cin >> a;
        ans += sum(n)-sum(arr[a]-1);
        update(arr[a]);
    }

    cout << ans;
}
