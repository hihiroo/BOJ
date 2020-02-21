//달려라 홍준
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int arr[4000005], size;

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = max(arr[i*2],arr[i*2+1]);
}

int f(int L, int R, int vtx, int nL, int nR){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return max(f(L,R,vtx*2,nL,mid),f(L,R,vtx*2+1,mid+1,nR));
}

int main(){
    int n,m,lv=1;
    cin>>n>>m;

    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++)
        scanf("%d",&arr[size+i]);
    construct();

    for(int i=m; i<=n-m+1; i++){
        printf("%d ",f(i-m+1,i+m-1,1,1,size+1));
    }
}
