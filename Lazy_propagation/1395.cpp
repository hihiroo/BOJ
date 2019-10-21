//스위치

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

int arr[400001],size,lazy[400001];
//lazy가 짝수면 그대로 홀수면 반전

void propagation(int idx, int nL, int nR){
    if(lazy[idx]){
        if(idx <= size){
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        if(lazy[idx] % 2)
            arr[idx] = (nR-nL+1)-arr[idx];
        lazy[idx] = 0;
    }
}

void update(int L, int R, int vtx, int nL, int nR){
    propagation(vtx,nL,nR);
    if(nL > R || nR < L) return;
    if(L <= nL && nR <= R){
        lazy[vtx]++;
        propagation(vtx,nL,nR);
    }
    else{
        int mid = (nL + nR)/2;
        update(L,R,vtx*2,nL,mid);
        update(L,R,vtx*2+1,mid+1,nR);
        arr[vtx] = arr[vtx*2] + arr[vtx*2+1];
    }
}

int sum(int L, int R, int vtx, int nL, int nR){
    propagation(vtx,nL,nR);
    if(nL > R || nR < L) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return sum(L,R,vtx*2,nL,mid)+sum(L,R,vtx*2+1,mid+1,nR);

}

int main(){
    int n,m;
    cin>>n>>m;
    int lv = 0;
    while(pow(2,lv) < n)
        size += pow(2,lv++);

    int q,s,f;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&q,&s,&f);
        if(s > f) swap(s,f);
        if(q) printf("%d\n",sum(s,f,1,1,size+1));
        else update(s,f,1,1,size+1);
    }
}


