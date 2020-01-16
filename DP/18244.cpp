// 변형 계단 수

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

lli dp[105][10][2][4]; //자릿수, 숫자, 감소증가, 횟수
lli mod = 1000000007;
int n;

lli f(int l, int num, bool inc, int cnt)
{
    if (num < 0 || num > 9 || cnt == 3)
        return 0;
    if (l == n)
        return 1;
    lli &ret = dp[l][num][inc][cnt];
    if (ret != -1)
        return ret;

    ret = 0;
    if (inc)
    {
        ret += f(l + 1, num + 1, 1, cnt + 1);
        ret += f(l + 1, num - 1, 0, 1);
    }
    else
    {
        ret += f(l + 1, num + 1, 1, 1);
        ret += f(l + 1, num - 1, 0, cnt + 1);
    }

    ret %= mod;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    lli ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += f(1, i, 1, 0);
        ans %= mod;
    }
    cout << ans;
}

