//나머지 합
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

lli arr[1000005], cnt[1000005];

int main(){
    int n,m;
    cin >> n >> m;

    lli ans = 0;

    for(int i=1; i<=n; i++){
        scanf("%lld",&arr[i]);
        arr[i] = (arr[i-1] + arr[i])%m;

        ans += cnt[arr[i]];
        cnt[arr[i]]++;
        if(arr[i] == 0) ans++;
    }
    cout << ans;
}
