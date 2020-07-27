//기타줄
#include <bits/stdc++.h>
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){
    cinFast();

    int n, m;
    cin >> n >> m;

    int a = 1e9, b = 1e9;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        a = min(a,x);
        b = min(b,y);
    }

    if(a >= b*6) return cout << b*n,0;

    int ans = 0;
    while(n >= 6){
        n -= 6;
        ans += a;
    }
    return cout << ans + min(a,b*n),0;
}
