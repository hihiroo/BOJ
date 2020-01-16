//Small World Network

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

int arr[105][105];
int main()
{
    fill(&arr[0][0], &arr[104][104], 10000);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int s, f;
        cin >> s >> f;
        arr[s][f] = 1;
        arr[f][s] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] > 6)
                return cout << "Big World!", 0;
        }
    }
    cout << "Small World!";
}

