// 수 고르기
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

lli arr[100005];

int main(){
    cinFast();

    lli n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr,arr+n);

    lli ans = 1e10;
    for(int i=0; i<n; i++){
        lli x = arr[i] + m;

        int idx = lower_bound(arr,arr+n,x)-arr;
        if(idx == n) continue;

        ans = min(ans,arr[idx]-arr[i]);
    }

    cout << ans;
}
