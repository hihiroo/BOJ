//돌아온 떡파이어
//뤼카 이론 + 중국인의 나머지 정리
// A % 100007 == A % (97*1031)
// A % 97 = a, A % 1031 = b 라고 하면
// 중국인의 나머지 정리에 의해
// A = (100007/97)*k1*a + (100007/1031)*k2*b
// k1, k2는 (100007/97)*k1 % 97 = 1,
// (100007/1031)*k2 % 1031 = 1 을 만족하는 수
// a, b는 뤼카 이론을 이용하여 빠르게 구함

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

lli mod[2]={97,1031}, k1 = 35, k2 = 659, dp[2][1500][1500];
// 1031*k1 % 97 = 1, 97*k2 % 1031 = 1

lli lucas(lli n, lli k, int mod_idx){
    lli ans = 1, m = mod[mod_idx];

    lli ni,ki;
    while(n&&k){
        ni=n%m;
        ki=k%m;
        n/=m;
        k/=m;
        ans=(ans*dp[mod_idx][ni][ki])%m;
    }
    return ans;
}

int main(){
    for(int p=0; p<2; p++){
        for(int i=0;i<=mod[p];i++){
            dp[p][i][0]=1;
            for(int j=1;j<=i;j++){
                dp[p][i][j]=(dp[p][i-1][j-1]+dp[p][i-1][j])%mod[p];
            }
        }
    }

    int t;
    cin>>t;
    for(; t>0; t--){
        lli n,m;
        cin>>n>>m;
        if(n+1 < m) cout<<"0"<<'\n';
        else if(m == 1){
            if(n > 0) cout<<"0"<<'\n';
            else cout<<"1"<<'\n';
        }
        else{
            lli ans = 1031*lucas(n-1,m-2,0)*k1;
            ans += 97*k2*lucas(n-1,m-2,1);
            ans %= 100007;
            cout<<ans<<'\n';
        }
    }
}
