//NC 문자열
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

#define mod 1000000007
int main(){
    lli n, NN=0, CC=0, NC=0, CN=0;
    cin>>n;
    string a;
    for(lli i=0; i<n; i++){
        cin>>a;
        bool N_appear = false, C_appear = false;
        bool NC_appear = false;
        for(int j=0; j<a.size(); j++){
            if(a[j] == 'N') N_appear = true;
            else if(a[j] == 'C'){
                if(N_appear){
                    NC_appear = true;
                    break;
                }
                else C_appear = true;
            }
        }
        if(NC_appear) NC++;
        else if(N_appear && C_appear) CN++;
        else if(N_appear) NN++;
        else if(C_appear) CC++;
    }
    //전체 순열 - 안되는 것(N,C,CN,C N,C CN,CN N,CCNN)
    lli cnt = 0, all = 0, N_all = 0, C_all = 0;
    for(lli i=n, pre=1; i>=1; i--){
        pre = (pre*i) % mod;
        all = (all+pre) % mod;
    }
    for(lli i=NN, pre=1; i>=1; i--){
        pre = (pre*i) % mod;
        N_all = (N_all+pre) % mod;
    }
    N_all++; // 공집합 추가
    for(lli i=CC, pre=1; i>=1; i--){
        pre = (pre*i) % mod;
        C_all = (C_all+pre) % mod;
    }
    C_all++; // 공집합 추가

    cnt += (((C_all*CN)%mod)*N_all)%mod; //C CN N 집합
    cnt += (C_all * N_all - 1) % mod; // C N 집합
    cnt %= mod;
    lli ans = (mod + all - cnt) % mod;
    printf("%lld",ans);
}
