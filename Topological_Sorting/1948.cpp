//임계경로

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

int in[10005], dist[10005], cnt;
map<pair<int, int>, int> road;
vector<vector<pair<int, int>>> v(10005);
vector<vector<int>> adj(10005);

void dfs(int vtx)
{
    for (int i = 0; i < adj[vtx].size(); i++)
    {
        int next = adj[vtx][i];
        if (road.find(mp(min(next, vtx), max(next, vtx))) != road.end())
            continue;
        cnt++;
        road[mp(min(next, vtx), max(next, vtx))] = 1;
        dfs(next);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f, cost;
        scanf("%d%d%d", &s, &f, &cost);
        v[s].pb(mp(f, cost));
        in[f]++;
    }

    int s, f;
    cin >> s >> f;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int vtx = q.front();
        q.pop();

        for (int i = 0; i < v[vtx].size(); i++)
        {
            int next = v[vtx][i].fst;
            int cost = dist[vtx] + v[vtx][i].snd;
            if (dist[next] <= cost)
            {
                if (cost == dist[next])
                    adj[next].pb(vtx);
                else
                {
                    adj[next].clear();
                    adj[next].pb(vtx);
                }
                dist[next] = cost;
            }
            if (--in[next] == 0)
                q.push(next);
        }
    }
    printf("%d\n", dist[f]);
    dfs(f);
    printf("%d", cnt);
}

