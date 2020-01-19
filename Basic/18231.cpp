//파괴된 도시

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

vector<vector<int>> v(2005);
bool destroy[2005], maked[2005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        v[s].pb(f);
        v[f].pb(s);
    }
    vector<int> ans;
    int ruin, k;
    cin >> ruin;
    for (int i = 0; i < ruin; i++)
    {
        scanf("%d", &k);
        destroy[k] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!destroy[i])
            continue;
        bool bomb = true;
        for (int j = 0; j < v[i].size(); j++)
        {
            int adj = v[i][j];
            if (!destroy[adj])
            {
                bomb = false;
                break;
            }
        }
        if (!bomb)
            continue;
        ans.pb(i);
        maked[i] = true;
        for (int j = 0; j < v[i].size(); j++)
        {
            int adj = v[i][j];
            maked[adj] = true;
        }
    }
    for (int i = 1; i <= n; i++)
        if (maked[i] != destroy[i])
            return cout << "-1", 0;

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

