// 타일 채우기
#include <math.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
int dtx[25000] = {1, 1, 5, 11, 36};
int f(int n)
{
    if (n < 0)
        return 0;
    if (dtx[n])
        return dtx[n];
    else
    {
        return dtx[n] = (f(n - 1) + 5 * f(n - 2) + f(n - 3) - f(n - 4));
    }
}
int main()
{
    int a, t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf(" %d", &a);
        printf("%d\n", f(a));
    }
    return 0;
}

