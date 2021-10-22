//신나는 함수 실행
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int dp[51][51][51];

int f(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(dp[a][b][c] != -1) return dp[a][b][c];

    if(a > 20 || b > 20 || c > 20)
        dp[a][b][c] = f(20,20,20);

    else if(a < b && b < c)
        dp[a][b][c] = f(a,b,c-1) + f(a,b-1,c-1) - f(a,b-1,c);
    else dp[a][b][c] = f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);

    return dp[a][b][c];
}

int main(){
    memset(dp, -1, sizeof(dp));
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a,b,c) << '\n';
    }
}
