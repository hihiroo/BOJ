//구간 합 구하기 3

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

int arr[5000][5000], size;

void construct()
{
    for (int i = size + 1; i <= 2 * size + 1; i++)
    {
        for (int j = size; j >= 1; j--)
            arr[i][j] = arr[i][j * 2] + arr[i][j * 2 + 1];
    }
    for (int i = size; i >= 1; i--)
    {
        for (int j = 1; j <= 2 * size + 1; j++)
            arr[i][j] = arr[i * 2][j] + arr[i * 2 + 1][j];
    }
}

void update(int y, int x, int val)
{
    int i = size + y;
    int j = size + x;
    arr[i][j] = val;
    while (i > 1)
    {
        i /= 2;
        arr[i][j] = arr[i * 2][j] + arr[i * 2 + 1][j];
    }
    while (j > 1)
    {
        j /= 2;
        i = size + y;
        arr[i][j] = arr[i][j * 2] + arr[i][j * 2 + 1];
        while (i > 1)
        {
            i /= 2;
            arr[i][j] = arr[i * 2][j] + arr[i * 2 + 1][j];
        }
    }
}

int sumX(int L, int R, int vtx, int nL, int nR, int i)
{
    if (nR < L || nL > R)
        return 0;
    if (L <= nL && nR <= R)
        return arr[i][vtx];
    int mid = (nL + nR) / 2;
    return sumX(L, R, vtx * 2, nL, mid, i) + sumX(L, R, vtx * 2 + 1, mid + 1, nR, i);
}

int sum(int Ly, int Ry, int Lx, int Rx, int vtx, int nL, int nR)
{
    if (nR < Ly || nL > Ry)
        return 0;
    if (Ly <= nL && nR <= Ry)
        return sumX(Lx, Rx, 1, 1, size + 1, vtx);
    int mid = (nL + nR) / 2;
    return sum(Ly, Ry, Lx, Rx, vtx * 2, nL, mid) + sum(Ly, Ry, Lx, Rx, vtx * 2 + 1, mid + 1, nR);
}

int main()
{
    int n, m, lv = 1;
    cin >> n >> m;
    while (lv <= n)
    {
        size += lv;
        lv *= 2;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[size + i][size + j]);

    construct();
    for (int i = 0; i < m; i++)
    {
        int w, y1, x1, y2, x2, val;
        scanf("%d", &w);
        if (w == 1)
        {
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            printf("%d\n", sum(y1, y2, x1, x2, 1, 1, size + 1));
        }
        else
        {
            scanf("%d%d%d", &y1, &x1, &val);
            update(y1, x1, val);
        }
    }
}


