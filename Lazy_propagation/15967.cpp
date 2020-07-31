//에바쿰
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

lli arr[4000005], lazy[4000005], size;

void construct(){
    for(int i=size; i>=1; i--)
        arr[i] = arr[i*2] + arr[i*2+1];
}

void propagation(int vtx, int nL, int nR){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] += lazy[vtx];
            lazy[vtx*2+1] += lazy[vtx];
        }
        arr[vtx] += (nR-nL+1)*lazy[vtx];
        lazy[vtx] = 0;
    }
}

lli f(int L, int R, int vtx, int nL, int nR, lli val){
    propagation(vtx,nL,nR);
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R){
        lazy[vtx] += val;
        propagation(vtx,nL,nR);
        return arr[vtx];
    }
    int mid = (nL + nR)/2;
    lli l = f(L,R,vtx*2,nL,mid,val);
    lli r = f(L,R,vtx*2+1,mid+1,nR,val);

    arr[vtx] = arr[vtx*2] + arr[vtx*2+1];

    return l + r;
}

int main(){
    cinFast();
    int n, q1, q2;
    cin >> n >> q1 >> q2;

    int lv = 1;
    while(lv < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++) cin >> arr[size+i];

    construct();

    for(int i=0; i<q1+q2; i++){
        int q;
        cin >> q;

        if(q == 1){
            int a, b;
            cin >> a >> b;
            cout << f(a,b,1,1,size+1,0) << '\n';
        }
        else{
            int s,e,l;
            cin >> s >> e >> l;
            f(s,e,1,1,size+1,l);
        }
    }
}
