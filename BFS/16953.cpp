// A->B

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

map<int, int> m;

int main()
{
    int a, b;
    cin >> a >> b;

    queue<int> q;
    q.push(b);
    m[b] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == a)
            return cout << m[now], 0;

        if (now % 2 == 0 && m.find(now / 2) == m.end())
        {
            m[now / 2] = m[now] + 1;
            q.push(now / 2);
        }
        if (now % 10 != 1)
            continue;
        int next = now / 10;
        if (next && m.find(next) == m.end())
        {
            m[next] = m[now] + 1;
            q.push(next);
        }
    }
    cout << "-1";
}


