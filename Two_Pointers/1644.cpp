//소수의 연속합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int p[4000005];
vector<int> v;

int main(){
    for(int i=2; i<=4000000; i++){
        if(p[i]) continue;
        v.pb(i);
        for(int j=2; i*j<=4000000; j++)
            p[i*j] = 1;
    }

    int n, cnt=0, sum=0, s=0, e=0;
    cin>>n;

    while(1){
        if(sum >= n) sum -= v[s++];
        else if(e == v.size()) break;
        else if(sum < n) sum += v[e++];
        if(sum == n) cnt++;
    }
    cout<<cnt;
}
