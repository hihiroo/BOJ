//XOR
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

int arr[2000001],size,lazy[2000001];

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = arr[i*2]^arr[i*2+1];
}
void propagate(int vtx, int nL, int nR){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] ^= lazy[vtx];
            lazy[vtx*2+1] ^= lazy[vtx];
        }
        else arr[vtx] ^= lazy[vtx];
        lazy[vtx] = 0;
    }
}
int f(int L, int R, int vtx, int nL, int nR){
    propagate(vtx,nL,nR);
    if(L > nR || nL > R) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return f(L,R,vtx*2,nL,mid)^f(L,R,vtx*2+1,mid+1,nR);
}
void update(int L, int R, int val, int vtx,int nL, int nR){
    propagate(vtx,nL,nR);
    if(L > nR || nL > R) return;
    if(L <= nL && nR <= R){
        lazy[vtx] ^= val;
        propagate(vtx,nL,nR);
    }
    else{
        int mid = (nL + nR)/2;
        update(L,R,val,vtx*2,nL,mid);
        update(L,R,val,vtx*2+1,mid+1,nR);
        arr[vtx] = arr[vtx*2]^arr[vtx*2+1];
    }
}


int main(){
    int n,m,t,a,b,c;
    cin>>n;
    int lv=0;
    while(pow(2,lv) < n){
        size += pow(2,lv);
        lv++;
    }
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[size+i]);
    construct();

    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&t,&a,&b);
        if(a > b) swap(a,b);
        if(t == 1){
            scanf("%d",&c);
            update(a+1,b+1,c,1,1,size+1);
        }
        else printf("%d\n",f(a+1,b+1,1,1,size+1));
    }
}

