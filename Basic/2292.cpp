//벌집
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    lli ans = 1;
    lli n, now=1;
    cin>>n;
    while(now < n){
        now += 6*ans;
        ans++;
    }
    cout<<ans;
}
