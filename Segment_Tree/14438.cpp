// 수열과 쿼리 17

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

vector<int> arr(400001);
int size;

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = min(arr[i*2],arr[i*2+1]);
}

void update(int idx, int val){
    arr[size+idx] = val;
    idx += size;
    while(idx > 1){
        idx/=2;
        arr[idx] = min(arr[idx*2],arr[idx*2+1]);
    }
}

int f(int L,int R,int vtx,int nL,int nR){
    if(nL > R || nR < L) return INT_MAX;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return min(f(L,R,vtx*2,nL,mid),f(L,R,vtx*2+1,mid+1,nR));
}

int main(){
    int n,m,a,lv=0,q,v;
    cin>>n;
    while(pow(2,lv) < n)
        size += pow(2,lv++);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[size+i]);

    construct();
    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&q,&a,&v);
        if(q == 2)
            printf("%d\n",f(a,v,1,1,size+1));
        else update(a,v);
    }
}



