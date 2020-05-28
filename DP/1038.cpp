//감소하는 수
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair
#define pii pair<int,int>

int dp[11][10];

int f(int len, int num){
    if(num < 0) return 0;
    if(len == 1) return 1;

    int &ret = dp[len][num];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=num-1; i>=0; i--)
        ret += f(len-1,i);

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));

    int n;
    cin >> n;
    n++;

    int len, poss = 0;
    for(int i=1; i<=10; i++){
        for(int j=0; j<=9; j++){
            if(f(i,j) >= n){
                poss = 1, len = i;
                printf("%d",j);
                break;
            }
            n -= f(i,j);
        }
        if(poss) break;
    }

    if(!poss) return cout << -1,0;

    for(int i=len-1; i>=1; i--){
        int cnt = 0;
        for(int j=0; j<=9; j++){
            if(cnt + f(i,j) >= n){
                n -= cnt;
                printf("%d",j);
                break;
            }
            cnt += f(i,j);
        }
    }
}