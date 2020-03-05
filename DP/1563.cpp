//개근상
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli mod = 1e6, dp[1005][2][3];

lli f(int day, int late, int absent){
    if(day == 0) return 1;
    lli &ret = dp[day][late][absent];
    if(ret != -1) return ret;

    ret = f(day-1,late,0);//출석
    if(absent < 2)//결석
        ret += f(day-1,late,absent+1);
    if(late == 0)//지각
        ret += f(day-1,late+1,0);

    ret %= mod;
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;
    cout<<f(n,0,0);
}
