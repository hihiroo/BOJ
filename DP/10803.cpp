//정사각형 만들기

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

int dp[10005][105];

int f(int n, int m)
{
    if (n < m)
        swap(n, m);
    if (n <= 0 || m <= 0)
        return 10000000;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n % m == 0)
        return n / m;

    dp[n][m] = 10000000;
    if (n >= m * 3)
    {
        dp[n][m] = f(n - m, m) + 1;
        return dp[n][m];
    }

    for (int i = 1; i <= max(n, m) / 2; i++)
    {
        if (i <= m / 2)
            dp[n][m] = min(dp[n][m], f(n, m - i) + f(n, i));
        if (i <= n / 2)
            dp[n][m] = min(dp[n][m], f(i, m) + f(n - i, m));
    }

    return dp[n][m];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    cout << f(n, m);
}

