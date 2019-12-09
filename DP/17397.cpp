// FLEX

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

int n, m, arr[1001], dp[1005][20][205];
//dp는 앞으로 느낄 박탈감
int f(int day, int pre, int money)
{
    //money는 남은 돈, pre는 전날 쓴 돈
    if (dp[day][pre][money] != -1)
        return dp[day][pre][money];
    if (day > n)
        return 0;

    dp[day][pre][money] = 1000000000;
    //i는 추가로 쓸 돈
    for (int i = min(money, max(0, pre - arr[day])); i >= 0; i--)
    {
        int cost = max(0, pre - (arr[day] + i));
        cost *= cost; //오늘 느끼는 박탈감
        dp[day][pre][money] = min(dp[day][pre][money], cost + f(day + 1, arr[day] + i, money - i));
    }
    return dp[day][pre][money];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    printf("%d", f(1, 0, m));
}
