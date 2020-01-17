//색종이와 쿼리

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

int tree[8000][8000], size;

void construct()
{
    for (int i = size + 1; i <= size + 1500; i++)
    {
        for (int j = size; j >= 1; j--)
        {
            tree[i][j] = max(tree[i][j * 2], tree[i][j * 2 + 1]);
        }
    }
    for (int i = size; i >= 1; i--)
    {
        for (int j = 1; j <= size + 1500; j++)
        {
            tree[i][j] = max(tree[i * 2][j], tree[i * 2 + 1][j]);
        }
    }
}

int xf(int L, int R, int vtx, int nL, int nR, int i)
{
    if (R < nL || L > nR)
        return 0;
    if (L <= nL && nR <= R)
        return tree[i][vtx];
    int mid = (nL + nR) / 2;
    return max(xf(L, R, vtx * 2, nL, mid, i), xf(L, R, vtx * 2 + 1, mid + 1, nR, i));
}

int solve(int Ly, int Ry, int Lx, int Rx, int vtx, int nL, int nR)
{
    if (Ry < nL || Ly > nR)
        return 0;
    if (Ly <= nL && nR <= Ry)
        return xf(Lx, Rx, 1, 0, size, vtx);
    int mid = (nL + nR) / 2;
    return max(solve(Ly, Ry, Lx, Rx, vtx * 2, nL, mid), solve(Ly, Ry, Lx, Rx, vtx * 2 + 1, mid + 1, nR));
}

int main()
{
    int n, m, lv = 1;
    cin >> n >> m;

    while (1500 > lv)
    {
        size += lv;
        lv *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        int y1, x1, y2, x2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        tree[size + 1 + y1][size + 1 + x1] += 1;
        tree[size + 1 + y1][size + 1 + x2] -= 1;
        tree[size + 1 + y2][size + 1 + x1] -= 1;
        tree[size + 1 + y2][size + 1 + x2] += 1;
    }
    for (int i = size + 1; i <= size + 1 + 1500; i++)
        for (int j = size + 1 + 1; j <= size + 1 + 1500; j++)
            tree[i][j] += tree[i][j - 1];
    for (int i = size + 1 + 1; i <= size + 1 + 1500; i++)
        for (int j = size + 1; j <= size + 1 + 1500; j++)
            tree[i][j] += tree[i - 1][j];

    construct();

    for (int i = 0; i < m; i++)
    {
        int y1, x1, y2, x2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        y2--, x2--;
        printf("%d\n", solve(y1, y2, x1, x2, 1, 0, size));
    }
}


