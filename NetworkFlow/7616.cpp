//교실로 가는길

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int f[5001][5001], chk[5001];
vector<vector<int>> ans(100), v(5001);
vector<int> par(5001, -1);

void flow(int s, int e, int k)
{
    for (int i = 0; i < 100; i++)
        ans[i].clear();
    fill(chk, chk + 5001, 0);
    int ans_size = 0;
    fill(&f[0][0], &f[5000][5001], 0);

    while (1)
    {
        for (int i = 1; i <= 5000; i++)
            par[i] = -1;
        queue<int> q;
        par[s] = s;
        q.push(s);
        while (!q.empty() && par[e] == -1)
        {
            int vtx = q.front();
            q.pop();
            for (int i = 0; i < v[vtx].size(); i++)
            {
                int next = v[vtx][i];
                if (par[next] == -1 && 1 > f[vtx][next] && !chk[next])
                {
                    par[next] = vtx;
                    q.push(next);
                }
            }
        }
        if (par[e] == -1)
            break;
        int poss = INT_MAX;
        for (int i = e; i != s; i = par[i])
            poss = min(poss, 1 - f[par[i]][i]);
        for (int i = e; i != s; i = par[i])
        {
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
            ans[ans_size].pb(i);
            chk[par[i]] = 1;
        }
        ans[ans_size++].pb(s);
        if (ans_size == k)
            break;
    }
    if (ans_size < k)
        printf("Impossible\n");
    else
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = ans[i].size() - 1; j >= 0; j--)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    printf("\n");
}
int main()
{
    int t = 0;
    while (1)
    {
        int k, n;
        cin >> k >> n;
        getchar();
        if (k == 0 && n == 0)
            return 0;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
            char space;
            int num;
            while (1)
            {
                scanf("%d%c", &num, &space);
                v[i].pb(num);
                if (space == '\n')
                    break;
            }
        }
        printf("Case %d:\n", ++t);
        flow(1, 2, k);
    }
}


