//약수의 합
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

lli sum[1000005];

int main(){
    for(int i=1; i<=1000000; i++){
        for(int j=1; i*j<=1000000; j++)
            sum[i*j] += i;
    }
    for(int i=1; i<=1000000; i++)
        sum[i] += sum[i-1];

    int t;
    cin>>t;
    for(; t>0; t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",sum[n]);
    }
}
