//하늘에서 떨어지는 1,2, ..., R-L+1개의 별
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli arr[400000], size;
lli lazyp[400000], lazym[400000];

void propagation(lli vtx){
    if(lazyp[vtx]){
        if(vtx <= size){
            lazyp[vtx*2] += lazyp[vtx];
            lazyp[vtx*2+1] += lazyp[vtx];
        }
        else arr[vtx] += (vtx-size)*lazyp[vtx];
        lazyp[vtx] = 0;
    }
    if(lazym[vtx]){
        if(vtx <= size){
            lazym[vtx*2] += lazym[vtx];
            lazym[vtx*2+1] += lazym[vtx];
        }
        else arr[vtx] -= lazym[vtx];
        lazym[vtx] = 0;
    }
}

void update(lli L, lli R, lli vtx, lli nL, lli nR, lli val){
    propagation(vtx);
    if(R < nL || L > nR) return;
    if(L <= nL && nR <= R){
        if(val == -1) lazyp[vtx]++;
        else lazym[vtx] += val;

        propagation(vtx);
        return;
    }
    lli mid = (nL + nR)/2;
    update(L,R,vtx*2,nL,mid,val);
    update(L,R,vtx*2+1,mid+1,nR,val);
}

int main(){
    lli n, lv = 1, q;
    cin>>n;

    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(lli i=size+1; i<=size+n; i++)
        scanf("%d",&arr[i]);

    cin>>q;

    lli t,l,r;
    while(q--){
        scanf("%lld%lld",&t,&l);
        if(t == 1){
            scanf("%lld",&r);
            update(l,r,1,1,size+1,-1);
            update(l,r,1,1,size+1,l-1);
        }
        else{
            update(l,l,1,1,size+1,0);
            printf("%lld\n",arr[size+l]);
        }
    }
}
