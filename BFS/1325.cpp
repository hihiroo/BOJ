//효율적인 해킹

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

vector<vector<int>> v(10005);
int visit[10005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        v[f].pb(s);
    }
    vector<pair<int, int>> ans(10005);
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        fill(visit, visit + 10005, 0);
        q.push(i);
        visit[i] = 1;

        int cnt = 0;
        while (!q.empty())
        {
            int vtx = q.front();
            q.pop();

            ans[i].fst = max(ans[i].fst, ++cnt);
            for (int j = 0; j < v[vtx].size(); j++)
            {
                int next = v[vtx][j];
                if (!visit[next])
                {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }
        ans[i].fst = -ans[i].fst;
        ans[i].snd = i;
    }
    sort(ans.begin() + 1, ans.begin() + n + 1);
    printf("%d ", ans[1].snd);
    for (int i = 2; i <= n; i++)
    {
        if (ans[i].fst != ans[1].fst)
            break;
        printf("%d ", ans[i].snd);
    }
}

