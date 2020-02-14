//수열과 쿼리 37
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int size, arr[100005], odd[400005], even[400005];

void construct(){
    for(int i=size; i>=1; i--){
        odd[i] = odd[i*2] + odd[i*2+1];
        even[i] = even[i*2] + even[i*2+1];
    }
}

void update(int idx, int val){
    if(arr[idx]%2 == val%2) return;
    arr[idx] = val;
    idx += size;
    if(val % 2 == 1){
        odd[idx] = 1;
        even[idx] = 0;
    }
    else{
        odd[idx] = 0;
        even[idx] = 1;
    }
    while(idx > 1){
        idx /= 2;
        odd[idx] = odd[idx*2] + odd[idx*2+1];
        even[idx] = even[idx*2] + even[idx*2+1];
    }
}

int solve(int L, int R, int vtx, int nL, int nR, int q){
    if(nL > R || nR < L) return 0;
    if(L <= nL && nR <= R){
        if(q == 2) return even[vtx];
        else return odd[vtx];
    }
    int mid = (nL + nR)/2;
    return solve(L,R,vtx*2,nL,mid,q)+solve(L,R,vtx*2+1,mid+1,nR,q);
}

int main(){
    int n, lv = 1, m;
    cin>>n;

    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        if(arr[i] % 2) odd[size+i] = 1;
        else even[size+i] = 1;
    }
    cin>>m;
    construct();

    int q,l,r;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&q,&l,&r);
        if(q == 1) update(l,r);
        else printf("%d\n",solve(l,r,1,1,size+1,q));
    }
}
