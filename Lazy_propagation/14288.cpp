// 내리 갈굼4

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

vector<vector<int>> v(100001);
vector<pair<int, int>> idx(100001);

int cnt, arr[400005], ya[400005], size, lazy[400005];

int dfs(int vtx)
{
    cnt++;
    idx[vtx].fst = cnt;
    for (int i = 0; i < v[vtx].size(); i++)
        dfs(v[vtx][i]);
    idx[vtx].snd = cnt;
}

void propagation(int vtx, int nL, int nR)
{
    if (lazy[vtx])
    {
        if (vtx <= size)
        {
            lazy[vtx * 2] += lazy[vtx];
            lazy[vtx * 2 + 1] += lazy[vtx];
        }
        arr[vtx] += (nR - nL + 1) * lazy[vtx];
        lazy[vtx] = 0;
    }
}

void update(int L, int R, int w, int vtx, int nL, int nR)
{
    propagation(vtx, nL, nR);
    if (nL > R || nR < L)
        return;
    if (L <= nL && nR <= R)
    {
        lazy[vtx] += w;
        propagation(vtx, nL, nR);
    }
    else
    {
        int mid = (nL + nR) / 2;
        update(L, R, w, vtx * 2, nL, mid);
        update(L, R, w, vtx * 2 + 1, mid + 1, nR);
        arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
    }
}

int sum(int L, int R, int vtx, int nL, int nR)
{
    propagation(vtx, nL, nR);
    if (nL > R || nR < L)
        return 0;
    if (L <= nL && nR <= R)
        return arr[vtx];
    int mid = (nL + nR) / 2;
    return sum(L, R, vtx * 2, nL, mid) + sum(L, R, vtx * 2 + 1, mid + 1, nR);
}

int ya_sum(int L, int R, int vtx, int nL, int nR)
{
    if (nL > R || nR < L)
        return 0;
    if (L <= nL && nR <= R)
        return ya[vtx];
    int mid = (nL + nR) / 2;
    return ya_sum(L, R, vtx * 2, nL, mid) + ya_sum(L, R, vtx * 2 + 1, mid + 1, nR);
}

int main()
{
    int n, m, r, q, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r);
        if (r == -1)
            continue;
        v[r].pb(i);
    }
    dfs(1); // 자기번호 ~ 부하들 번호 넘버링

    int lv = 0;
    while (pow(2, lv) < n)
        size += pow(2, lv++);

    bool yaja = false;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &q);
        if (q == 3)
        {
            yaja ^= 1;
            continue;
        }
        else
        {
            scanf("%d", &a);
            int L = idx[a].fst;
            int R = idx[a].snd;

            if (q == 1)
            {
                scanf("%d", &b);
                if (!yaja)
                    update(L, R, b, 1, 1, size + 1);
                else
                {
                    int idx = size + L;
                    ya[idx] += b;
                    while (idx > 1)
                    {
                        idx /= 2;
                        ya[idx] = ya[idx * 2] + ya[idx * 2 + 1];
                    }
                }
            }
            else
                printf("%d\n", sum(L, L, 1, 1, size + 1) + ya_sum(L, R, 1, 1, size + 1));
        }
    }
}

