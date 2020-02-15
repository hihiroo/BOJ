//수열과 쿼리13
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli size, mod = 1e9+7, arr[400005];
lli lazym[400005]={1,}, lazyp[400005];

void propagation(lli nL, lli nR, lli vtx){
    if(lazym[vtx] != 1 || lazyp[vtx]){
        if(vtx <= size){
            lazyp[vtx*2] *= lazym[vtx];
            lazyp[vtx*2+1] *= lazym[vtx];
            lazyp[vtx*2] %= mod, lazyp[vtx*2+1] %= mod;

            lazym[vtx*2] *= lazym[vtx];
            lazym[vtx*2+1] *= lazym[vtx];
            lazym[vtx*2] %= mod, lazym[vtx*2+1] %= mod;

            lazyp[vtx*2] += lazyp[vtx];
            lazyp[vtx*2+1] += lazyp[vtx];
            lazyp[vtx*2] %= mod, lazyp[vtx*2+1] %= mod;
        }
        arr[vtx] *= lazym[vtx];
        arr[vtx] += (nR-nL+1)*lazyp[vtx];
        arr[vtx] %= mod;
        lazym[vtx] = 1, lazyp[vtx] = 0;
    }
}

void construct(){
    for(lli i=size; i>0; i--)
        arr[i] = (arr[i*2] + arr[i*2+1])%mod;
}

lli f(lli L, lli R, lli vtx, lli nL, lli nR, lli q, lli val){
    propagation(nL,nR,vtx);
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R){
        if(q == 3){
            lazym[vtx] = 0;
            propagation(nL,nR,vtx);
            lazyp[vtx] = val;
        }
        else if(q == 2) lazym[vtx] = val;
        else if(q == 1) lazyp[vtx] = val;
        propagation(nL,nR,vtx);
        return arr[vtx];
    }
    lli mid = (nL + nR)/2;
    lli left = f(L,R,vtx*2,nL,mid,q,val);
    lli right = f(L,R,vtx*2+1,mid+1,nR,q,val);
    arr[vtx] = (arr[vtx*2] + arr[vtx*2+1])%mod;
    return (left + right) % mod;
}

int main(){
    lli n,m,lv=1;
    cin>>n;

    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++)
        scanf("%lld",&arr[size+i]);
    construct();

    lli q,x,y,v;
    cin>>m;
    for(; m>0; m--){
        scanf("%lld%lld%lld",&q,&x,&y);
        if(q == 4) printf("%lld\n",f(x,y,1,1,size+1,4,0));
        else{
            scanf("%lld",&v);
            f(x,y,1,1,size+1,q,v);
        }
    }
}
