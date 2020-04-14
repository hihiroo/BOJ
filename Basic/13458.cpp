//시험감독
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

lli arr[1000005];

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    lli b,c;
    cin >> b >> c;

    lli ans = n;
    for(int i=1; i<=n; i++){
        arr[i] -= b;
        if(arr[i] > 0) ans += arr[i]%c ? arr[i]/c+1 : arr[i]/c;
    }

    cout << ans;
}
