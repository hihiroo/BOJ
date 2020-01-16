//네모네모 시력검사

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

char arr[105][105];
int main()
{
    int n, m;
    cin >> n >> m;

    int up = 0, down = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                cnt++;
        }
        if (cnt > 2)
        {
            if (up)
                down = cnt;
            else
                up = cnt;
        }
    }
    if (up < down)
        return cout << "UP", 0;
    if (down < up)
        return cout << "DOWN", 0;

    int right = 0, left = 0;
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (arr[i][j] == '#')
                cnt++;
        if (cnt > 2)
        {
            if (left)
                right = cnt;
            else
                left = cnt;
        }
    }
    if (right < left)
        cout << "RIGHT";
    else
        cout << "LEFT";
}

