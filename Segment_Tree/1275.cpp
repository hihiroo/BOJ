//커피숍2

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


lli arr[400001];
int size;

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = arr[i*2] + arr[i*2+1];
}

lli sum(int L, int R, int vtx, int nodeL, int nodeR){
    if(nodeR < L || R < nodeL) return 0;
    if(L <= nodeL && nodeR <= R) return arr[vtx];
    int mid = (nodeL + nodeR)/2;
    return sum(L,R,vtx*2,nodeL,mid)+sum(L,R,vtx*2+1,mid+1,nodeR);
}

void update(int i, int val){
    i += size;
    arr[i] = (lli)val;
    while(i > 1){
        i/=2;
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    int lv = 0;
    while(pow(2,lv) <= n){
        size += pow(2,lv);
        lv++;
    }
    for(int i=1; i<=n; i++)
        scanf("%lld",&arr[size+i]);
    construct();

    int x,y,a,b;
    for(int i=0; i<q; i++){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        if(x > y) swap(x,y);
        printf("%lld\n",sum(x,y,1,1,size+1));
        update(a,b);
    }
}


