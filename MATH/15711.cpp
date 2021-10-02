// 환상의 짝꿍
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int chk[3000005];
vector<int> v;

int main(){
    for(int i=2; i<=3000000; i++){
        if(chk[i]) continue;
        v.pb(i);
        for(int j=2; i*j<=3000000; j++) chk[i*j] = 1;
    }

    int t;
    cin >> t;

    while(t--){
        long long a, b, n;
        cin >> a >> b;

        n = a+b;
        if(n < 4) cout << "NO\n";
        else if(n % 2 == 0) cout << "YES\n";
        else{
            n -= 2;
            // n이 소수인지 확인
            int p = 1;
            for(int i=0; i<v.size()&&(lli)v[i]*(lli)v[i]<=n; i++){
                if(n % v[i] == 0){
                    p = 0;
                    break;
                }
            }
            if(p) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
