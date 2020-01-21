//타일 채우기2

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

lli n, mod = 1000000007;

vector<vector<lli>> gop(vector<vector<lli>> a, vector<vector<lli>> b)
{
    vector<vector<lli>> ans(2);
    for (lli i = 0; i < 2; i++)
    {
        for (lli j = 0; j < 2; j++)
        {
            ans[i].pb(0);
            for (lli k = 0; k < 2; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] = (ans[i][j] + mod) % mod;
            }
        }
    }
    return ans;
}

vector<vector<lli>> fast_gop(vector<vector<lli>> v, lli m)
{
    if (m == 1)
        return v;
    if (m % 2)
        return gop(v, fast_gop(v, m - 1));
    vector<vector<lli>> tmp = fast_gop(v, m / 2);
    return gop(tmp, tmp);
}

int main()
{
    cin >> n;
    if (n % 2)
        return cout << "0", 0;
    n /= 2;
    if (n == 1)
        return cout << "3", 0;
    vector<vector<lli>> k(2);
    k[0].pb(4), k[0].pb(-1);
    k[1].pb(1), k[1].pb(0);
    k = fast_gop(k, n - 1);
    lli ans = 0;
    ans += k[0][0] * 3 + k[0][1] * 1;
    cout << (ans + mod) % mod;
}
