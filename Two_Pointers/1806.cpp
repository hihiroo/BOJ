//부분합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


int arr[100005];

int main(){
    int n, S;
    cin>>n>>S;
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);

    int s = 1, e = 0, sum = 0, ans = 100001;
    while(1){
        if(sum >= S) sum -= arr[s++];
        else if(e > n) break;
        else if(sum < S) sum += arr[++e];
        if(sum >= S && s <= e) ans = min(ans,e-s+1);
    }
    if(ans > 100000) cout<<0;
    else cout<<ans;
}
