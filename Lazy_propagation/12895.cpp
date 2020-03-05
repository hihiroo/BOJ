//화려한 마을
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n,arr[400000], size, lazy[400000];

void propagation(int vtx){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] = lazy[vtx];
            lazy[vtx*2+1] = lazy[vtx];
        }
        arr[vtx] = lazy[vtx];
        lazy[vtx] = 0;
    }
}

void construct(){
    for(int i=size+n; i>=1; i--)
        arr[i] = 1;
}

int f(int L, int R, int vtx, int nL, int nR, int color){
    propagation(vtx);
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R){
        if(color != -1){
            lazy[vtx] = (1<<color);
            propagation(vtx);
        }
        return arr[vtx];
    }
    int mid = (nL + nR)/2;
    int left = f(L,R,vtx*2,nL,mid,color);
    int right = f(L,R,vtx*2+1,mid+1,nR,color);
    arr[vtx] = (arr[vtx*2] | arr[vtx*2+1]);

    return (left|right);
}

int main(){
    int t,q,lv=1;
    scanf("%d %d %d",&n,&t,&q);

    while(size < n){
        size += lv;
        lv *= 2;
    }

    construct();

    char quest;
    int x,y,z;
    for(; q>0; q--){
        scanf(" %c %d %d",&quest,&x,&y);
        if(x > y) swap(x,y);

        if(quest == 'C'){
            scanf(" %d",&z);
            f(x,y,1,1,size+1,z-1);
        }
        else{
            int ret = f(x,y,1,1,size+1,-1);
            int ans = 0;
            while(ret > 0){
                if(ret%2) ans++;
                ret/=2;
            }
            printf("%d\n",ans);
        }
    }
}
