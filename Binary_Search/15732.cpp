//도토리 숨기기

#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int arr[10000][3], d, n, k;
lli box;

bool up(int height)
{
    lli sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i][0] > height)
            continue;
        int lim = min(height, arr[i][1]);
        sum += max(0, (lim - arr[i][0]) / arr[i][2] + 1);
    }
    return sum < d;
}

int main()
{

    cin >> n >> k >> d;

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
        box = box + 1 + (arr[i][1] - arr[i][0]) / arr[i][2];
    }

    d = d % box;
    if (d == 0)
        d = box;

    int s = 0, f = 1000001;
    while (s + 1 < f)
    {
        int mid = (s + f) / 2;
        if (up(mid))
            s = mid;
        else
            f = mid;
    }
    printf("%d", f);
}


