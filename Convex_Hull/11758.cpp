//ccw

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

pair<int, int> p1, p2, p3;

int main()
{
    cin >> p1.fst >> p1.snd;
    cin >> p2.fst >> p2.snd;
    cin >> p3.fst >> p3.snd;

    pair<int, int> v1, v2;
    v1.fst = p2.fst - p1.fst;
    v1.snd = p2.snd - p1.snd;
    v2.fst = p3.fst - p2.fst;
    v2.snd = p3.snd - p2.snd;

    int res = v1.fst * v2.snd - v2.fst * v1.snd;
    if (res == 0)
        printf("0");
    else if (res > 0)
        printf("1");
    else
        printf("-1");
}

