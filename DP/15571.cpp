//블록 3

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

int num[1005] = {1}, n, dp[1000005] = {1, 1};

int f(int k)
{
    if (k < 0)
        return 0;
    if (num[k])
        return num[k];
    for (int i = 1; i <= k; i++)
    {
        num[k] += f(k - i);
        num[k] %= 1999;
    }
    return num[k];
}

int solve(int k)
{
    if (k < 0)
        return 0;
    if (dp[k])
        return dp[k];

    dp[k] = (f(n) - 1) * solve(k - n) + 2 * solve(k - 1) - f(n) * solve(k - n - 1);
    dp[k] = (dp[k] % 1999 + 1999) % 1999;
    return dp[k];
}

int main()
{
    int m;
    cin >> n >> m;
    cout << solve(m);
}
