// 최애 정하기

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

int f[2005][2005], c[2005][2005];
vector<vector<int>> v(2005);

map<string, int> num;

int flow(int s, int e)
{
    int ans = 0;
    while (1)
    {
        vector<int> par(2005, -1);
        queue<int> q;
        q.push(s);
        par[s] = s;

        while (!q.empty() && par[e] == -1)
        {
            int vtx = q.front();
            q.pop();

            for (int i = 0; i < v[vtx].size(); i++)
            {
                int next = v[vtx][i];
                if (par[next] < 0 && f[vtx][next] < c[vtx][next])
                {
                    par[next] = vtx;
                    q.push(next);
                }
            }
        }

        if (par[e] == -1)
            break;
        int poss = 10000000;
        for (int i = e; i != s; i = par[i])
            poss = min(poss, c[par[i]][i] - f[par[i]][i]);

        for (int i = e; i != s; i = par[i])
        {
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }

        ans += poss;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    string name;
    for (int i = 1; i <= m; i++)
    {
        cin >> name;
        num[name] = n + i;
        c[n + i][2001] = 1; // 싱크랑 연결
        v[n + i].pb(2001), v[2001].pb(n + i);
    }
    for (int i = 1; i <= n; i++)
    {
        c[0][i] = 1; //소스랑 연결
        v[0].pb(i), v[i].pb(0);
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> name;
            int k_num = num[name];
            c[i][k_num] = 1;
            v[i].pb(k_num), v[k_num].pb(i);
        }
    }

    int ans = flow(0, 2001);
    if (ans < n)
        printf("NO\n%d", ans);
    else
        printf("YES");
}

