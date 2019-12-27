//cows

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

struct P
{
    lli x, y;
    lli p, q;
} v[100005];

bool cmp(P A, P B)
{
    if (A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}

bool cmp2(P A, P B)
{
    if (A.p * B.q != A.q * B.p)
        return A.q * B.p < A.p * B.q;
    if (A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}

lli ccw(P v1, P v2, P v3)
{ //v1v2 v2v3
    return (v2.x - v1.x) * (v3.y - v2.y) - (v2.y - v1.y) * (v3.x - v2.x);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &v[i].x, &v[i].y);
    sort(v, v + n, cmp);
    for (int i = 1; i < n; i++)
    {
        v[i].p = v[i].x - v[0].x;
        v[i].q = v[i].y - v[0].y;
    }
    sort(v + 1, v + n, cmp2);

    stack<int> s;
    s.push(0);
    s.push(1);
    int next = 2;
    while (next < n)
    {
        while (s.size() >= 2)
        {
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            int v3 = next;
            if (ccw(v[v1], v[v2], v[v3]) > 0)
            {
                s.push(v2);
                break;
            }
        }
        s.push(next++);
    }

    double sum = 0;
    while (s.size() >= 3)
    {
        int v1 = s.top();
        s.pop();
        int v2 = s.top();
        sum += ((double)ccw(v[0], v[v1], v[v2])) / 2.0;
    }
    cout << (int)abs(sum) / 50;
}

