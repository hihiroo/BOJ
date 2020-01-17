// 걷다보니 신척역 삼(Large)

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

lli dp[33336][3][3], mod = 1000000009;
int n;

lli f(int l, int num, int sum)
{
    if (l == n)
    {
        if ((sum + num) % 3 == 0)
            return 1;
        else
            return 0;
    }
    lli &ret = dp[l][num][sum];
    if (ret != -1)
        return ret;

    ret = f(l + 1, 0, sum);
    ret += f(l + 1, 1, (sum + 1) % 3);
    ret %= mod;
    ret += f(l + 1, 2, (sum + 2) % 3);
    ret %= mod;

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;

    lli ans = 0;
    ans = f(1, 1, 1) + f(1, 2, 2);
    ans %= mod;
    cout << ans;
}

