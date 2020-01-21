//블록 2

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

int num[105] = {1}, n;

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

vector<vector<int>> gop(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i].pb(0);
            for (int t = 0; t < n; t++)
            {
                ans[i][j] += a[i][t] * b[t][j];
                ans[i][j] %= 1999;
            }
        }
    }
    return ans;
}

vector<vector<int>> fast_gop(lli k, vector<vector<int>> v)
{
    if (k <= 1)
        return v;
    vector<vector<int>> a(n);
    if (k % 2)
    {
        a = fast_gop(k - 1, v);
        return gop(a, v);
    }
    else
    {
        a = fast_gop(k / 2, v);
        return gop(a, a);
    }
}

int main()
{
    lli m;
    cin >> n >> m;
    vector<vector<int>> k(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j == n - 1)
                    k[i].pb(f(n));
                else
                    k[i].pb(1);
            }
            else
            {
                if (i - 1 == j)
                    k[i].pb(1);
                else
                    k[i].pb(0);
            }
        }
    }
    int ans = 0;
    if (n <= m)
    {
        k = fast_gop(m - n + 1, k);
        for (int i = 0; i < n; i++)
        {
            ans += k[0][i] * f(n - i - 1);
            ans %= 1999;
        }
    }
    else
        ans = f(m);
    cout << ans;
}

