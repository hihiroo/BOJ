//정수게임

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

lli n,k,arr[20];

lli gcd(lli a, lli b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    cin>>n>>k;
    for(lli i=0; i<k; i++)
        cin>>arr[i];

    lli ans = 0;

    for(lli i=1; i<(1<<k); i++){
        lli cnt = 0, gop = 1;

        for(int j=0; j<k; j++)
            if(i & (1<<j)){
                cnt++;
                gop = gop*arr[j]/gcd(gop,arr[j]);
            }

        if(cnt % 2) ans += n/gop;
        else ans -= n/gop;
    }
    cout<<n-ans;
}


