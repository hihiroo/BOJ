//다각형의 면적

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

vector<pair<double, double>> v(10005);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i].fst >> v[i].snd;

    double sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        pair<double, double> vec1, vec2;
        vec1.fst = v[i].fst - v[0].fst;
        vec1.snd = v[i].snd - v[0].snd;
        vec2.fst = v[i + 1].fst - v[0].fst;
        vec2.snd = v[i + 1].snd - v[0].snd;
        sum += (vec1.fst * vec2.snd - vec2.fst * vec1.snd) / 2;
    }
    printf("%.1f", abs(sum));
}

