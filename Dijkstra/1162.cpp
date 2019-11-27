//도로포장

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long

lli dp[10005][25], n, m, k, INF = 10000000000;
vector<vector<pair<lli, lli>>> v(10005);

lli f(lli vtx, lli k)
{
    if (vtx == 1)
        return 0;
    if (dp[vtx][k] != -1)
        return dp[vtx][k];

    dp[vtx][k] = INF;
    for (int i = 0; i < v[vtx].size(); i++)
    {
        int next = v[vtx][i].fst;
        int cost = v[vtx][i].snd;
        if (k)
            dp[vtx][k] = min(dp[vtx][k], f(next, k - 1));
        dp[vtx][k] = min(dp[vtx][k], f(next, k) + cost);
    }

    return dp[vtx][k];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> k;
    for (lli i = 0; i < m; i++)
    {
        lli s, e, cost;
        scanf("%lld%lld%lld", &s, &e, &cost);
        v[s].pb(mp(e, cost));
        v[e].pb(mp(s, cost));
    }
    cout << f(n, k);
}