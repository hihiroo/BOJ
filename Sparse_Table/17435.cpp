//합성함수와 쿼리
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int f[200005][100];

int main(){
    int m;
    cin >> m;
    for(int i=1; i<=m; i++)
        scanf("%d",&f[i][0]);

    for(int i=1; (1<<i)<=500000; i++)
        for(int j=1; j<=m; j++)
            f[j][i] = f[f[j][i-1]][i-1];

    int q, n, x;
    cin >> q;

    while(q--){
        scanf("%d%d",&n,&x);

        for(int i=0; (1<<i)<=n; i++)
            if((1<<i) & n) x = f[x][i];

        printf("%d\n",x);
    }
}
