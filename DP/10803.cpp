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
    if (n <= 0 || m <= 0)
        return 0;
    if (max(n, m) % min(n, m) == 0)
        return max(n, m) / min(n, m);
    if (dp[n][m])
        return dp[n][m];

    dp[n][m] = 100000000;
    for (int i = 1; i <= min(n, m); i++)
    {
        dp[n][m] = min(dp[n][m], 1 + f(n - i, i) + f(n, m - i));
        dp[n][m] = min(dp[n][m], 1 + f(n - i, m) + f(i, m - i));
    }

    printf("%d %d %d\n", n, m, dp[n][m]);
    return dp[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << f(n, m);
}


