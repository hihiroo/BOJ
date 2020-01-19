// 캠프 준비
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

lli n, l, r, x;
lli arr[16], cnt;

void f(lli num, lli sum, vector<lli> k)
{
    if (num == n + 1)
    {
        sort(k.begin(), k.end());
        if (sum >= l && sum <= r && k.size() > 1)
        {
            if (k[k.size() - 1] - k[0] >= x)
                cnt++;
        }
        return;
    }
    f(num + 1, sum, k);
    sum += arr[num];
    k.pb(arr[num]);
    f(num + 1, sum, k);
    return;
}

int main()
{
    cin >> n >> l >> r >> x;
    for (lli i = 1; i <= n; i++)
        cin >> arr[i];
    vector<lli> k;
    f(1, 0, k);
    cout << cnt;
}

