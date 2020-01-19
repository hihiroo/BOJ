//피보나치 수 6
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

map<lli, lli> dp;
lli mod = 1000000007;

lli f(lli n)
{
    if (dp.find(n) != dp.end())
        return dp[n];
    if (n % 2)
    {
        lli x = f((n + 1) / 2);
        lli y = f((n + 1) / 2 - 1);
        dp[n] = ((x * x) % mod) + ((y * y) % mod);
    }
    else
    {
        lli x = f(n / 2 - 1);
        lli y = f(n / 2);
        dp[n] = ((x * 2 + y) % mod) * y;
    }
    dp[n] %= mod;
    return dp[n];
}

int main()
{
    dp[0] = 0;
    dp[1] = 1;
    lli n;
    cin >> n;
    cout << f(n);
}

