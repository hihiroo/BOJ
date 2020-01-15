//초콜릿 자르기

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

int dp[1005][1005];

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (dp[j][i] != -1)
            {
                dp[i][j] = dp[j][i];
                continue;
            }
            if (max(i, j) % min(i, j) == 0)
            {
                dp[i][j] = max(i, j) / min(i, j);
                continue;
            }
            if (min(i, j) * 3 <= max(i, j))
            {
                if (i < j)
                    dp[i][j] = 1 + dp[i][j - i];
                else
                    dp[i][j] = 1 + dp[i - j][j];
                continue;
            }
            dp[i][j] = 100000000;
            for (int k = 1; k <= i / 2; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            for (int k = 1; k <= j / 2; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
        }
    }
    cout << dp[n][m];
}

