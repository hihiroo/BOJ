//군인
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int arr[2000005],size;

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = arr[i*2] + arr[i*2+1];
}

void update(int idx, int val){
    idx += size;
    arr[idx] += val;
    while(idx > 1){
        idx /= 2;
        arr[idx] = arr[idx*2] + arr[idx*2+1];
    }
}

int f(int L, int R, int vtx, int val){
    if(L == R) return L;
    int mid = (L+R)/2;
    if(arr[vtx*2] >= val) return f(L,mid,vtx*2,val);
    else return f(mid+1,R,vtx*2+1,val-arr[vtx*2]);
}

int main(){
    int n,m,lv=1;
    cin>>n;
    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++)
        scanf("%d",&arr[size+i]);

    construct();

    cin>>m;

    int q,i,a;
    for(; m>0; m--){
        scanf("%d%d",&q,&i);
        if(q == 1){
            scanf("%d",&a);
            update(i,a);
        }
        else printf("%d\n",f(1,size+1,1,i));
    }
}
