//달리기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


int size, arr[2000005], q[500000], s[500000];

void update(int idx){
    arr[idx]++;
    while(idx > 1){
        idx /= 2;
        arr[idx] = arr[idx*2] + arr[idx*2+1];
    }
}

int f(int L, int R, int vtx, int nL, int nR){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return f(L,R,vtx*2,nL,mid)+f(L,R,vtx*2+1,mid+1,nR);
}

int main(){
    int n, lv=1;
    cin>>n;

    while(size < n){
        size += lv;
        lv *= 2;
    }

    map<int,int> hasing;
    for(int i=0; i<n; i++){
        scanf("%d",&q[i]);
        s[i] = q[i];
    }
    sort(s,s+n);

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(hasing[s[i]]) continue;
        hasing[s[i]] = ++cnt;
    }

    for(int i=0; i<n; i++){
        printf("%d\n",f(hasing[q[i]],n,1,1,size+1)+1);
        update(size+hasing[q[i]]);
    }
}
