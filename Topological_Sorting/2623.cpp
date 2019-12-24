//음악 프로그램

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

vector<vector<int>> v(1005);
int in[1005];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int k, pre, a;
        cin >> k >> pre;
        for (int i = 1; i < k; i++)
        {
            cin >> a;
            v[pre].pb(a);
            in[a]++;
            pre = a;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i])
            continue;
        q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int vtx = q.front();
        q.pop();
        ans.pb(vtx);
        for (int i = 0; i < v[vtx].size(); i++)
        {
            int next = v[vtx][i];
            if (--in[next] == 0)
                q.push(next);
        }
    }

    if (ans.size() != n)
        printf("0");
    else
    {
        for (int i = 0; i < ans.size(); i++)
            printf("%d\n", ans[i]);
    }
}


