//수열의 구간 평균
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

/* 1~i번째까지의 합이 sum이고 1~j까지의 합을 sum'이라고 하자
j+1~i까지의 평균이 k라면 k(i-j) = sum-sum'
sum - ki = sum'-kj 이다.
따라서 sum'-kj가 sum-ki인 j의 개수를 다 더하면 된다.
*/

map<lli,lli> cnt;

int main(){
    cinFast();

    lli a, n, k, sum = 0, ans = 0;
    cin >> n >> k;

    cnt[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> a;
        sum += a;

        lli target = sum-k*i;
        ans += cnt[target];

        cnt[sum-i*k]++;
    }
    cout << ans;
}
