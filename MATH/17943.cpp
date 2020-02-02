//도미노 예측
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


int arr[200005];
int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<n; i++){
        scanf("%d",&arr[i]);
        arr[i] ^= arr[i-1];
    }
    for(int i=0; i<q; i++){
        int p,x,y,d;
        scanf("%d%d%d",&p,&x,&y);
        if(p == 0)
            printf("%d\n",arr[x-1]^arr[y-1]);
        else{
            scanf("%d",&d);
            printf("%d\n",arr[x-1]^arr[y-1]^d);
        }
    }
}
