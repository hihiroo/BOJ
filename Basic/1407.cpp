//2로 몇 번 나누어 떨어질까

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

int main()
{
    lli a, b;
    cin >> a >> b;
    a--;

    lli lv = 1, sum = 0, cnt = 0;
    while (lv * 2 <= b)
        lv *= 2;

    for (lli i = lv; i > 0; i /= 2)
    {
        lli inc = b / i - a / i;
        sum += i * (inc - cnt);
        cnt += (inc - cnt);
    }
    cout << sum;
}

