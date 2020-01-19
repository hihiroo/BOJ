//소수 경로

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

int chk[100000] = {1, 1};
int visit[100000];

int main()
{
    for (int i = 2; i < 100000; i++)
    {
        if (chk[i])
            continue;
        for (int j = 2; i * j < 100000; j++)
            chk[i * j] = 1;
    }

    int t;
    cin >> t;
    for (; t > 0; t--)
    {
        fill(visit, visit + 100000, -1);

        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a), visit[a] = 0;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            if (now == b)
            {
                printf("%d\n", visit[now]);
                break;
            }

            int a[4];
            a[0] = now % 10, a[1] = (now % 100) / 10;
            a[2] = (now % 1000) / 100, a[3] = now / 1000;
            for (int i = 0; i <= 3; i++)
            {
                int origin = a[i];
                for (int j = 0; j <= 9; j++)
                {
                    a[i] = j;
                    int next = a[0] + a[1] * 10 + a[2] * 100 + a[3] * 1000;
                    if (next >= 1000 && visit[next] == -1 && !chk[next])
                    {
                        visit[next] = visit[now] + 1;
                        q.push(next);
                    }
                }
                a[i] = origin;
            }
        }
        if (visit[b] == -1)
            printf("Impossible\n");
    }
}

