#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n, arr[100001], root[100001];

int find_root(int a)
{
    if (a < 0)
        return -1;
    if (root[a] == a)
        return a;
    return root[a] = find_root(root[a]);
}
bool poss(lli lv)
{
    lli s = 0, e = lv;
    for (int i = 0; i < n; i++)
    {
        //e-s보다 시간이 작거나 같은 문제 중에 안 푼 문제 찾기
        int idx = find_root(upper_bound(arr, arr + n, e - s) - arr - 1);
        if (idx == -1)
            return 0; //찾을 수 없음 -> 불가능
        if (e - arr[idx] >= e - lv)
            ;
        else
            s = e - lv; // 시간이 서로 겹치면 s위치 바꿈
        e += lv;
        root[idx] = idx - 1;
    }
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    lli s = 0, f = 1000000001, mid;
    while (s + 1 < f)
    {
        mid = (s + f) / 2;
        for (int i = 0; i < n; i++)
            root[i] = i;
        if (poss(mid))
            f = mid;
        else
            s = mid;
    }
    cout << f;
}
