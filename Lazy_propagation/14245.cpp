//XOR
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int arr[500005], lazy[2000005], size;

void propagation(int nL, int nR, int vtx){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] ^= lazy[vtx];
            lazy[vtx*2+1] ^= lazy[vtx];
        }
        else arr[vtx-size] ^= lazy[vtx];
        lazy[vtx] = 0;
    }
}

void f(int L, int R, int vtx, int nL, int nR, int val){
    propagation(nL,nR,vtx);
    if(R < nL || L > nR) return;
    if(L <= nL && nR <= R){
        lazy[vtx] ^= val;
        propagation(nL,nR,vtx);
        return;
    }
    int mid = (nL + nR)/2;
    f(L,R,vtx*2,nL,mid,val), f(L,R,vtx*2+1,mid+1,nR,val);
}

int main(){
    int n,lv=1,m;
    cin>>n;
    while(size < n){
        size += lv;
        lv *= 2;
    }
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);

    cin>>m;
    for(; m>0; m--){
        int t,a,b,c;
        scanf("%d%d",&t,&a);
        if(t == 1){
            scanf("%d%d",&b,&c);
            f(a+1,b+1,1,1,size+1,c);
        }
        else{
            f(a+1,a+1,1,1,size+1,0);
            printf("%d\n",arr[a+1]);
        }
    }
}
