//주식회사 승범이네
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > v(100005);
pair<int,int> range[100005];
int cnt, arr[400005], lazy[400005],size;

void numbering(int vtx){
    range[vtx].fst = cnt+1;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        numbering(next);
    }
    range[vtx].snd = ++cnt;
}

void propagation(int nL, int nR, int vtx){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] += lazy[vtx];
            lazy[vtx*2+1] += lazy[vtx];
        }
        arr[vtx] += (nR-nL+1)*lazy[vtx];
        lazy[vtx] = 0;
    }
}

void f(int L, int R, int vtx, int nL, int nR, int val){
    propagation(nL,nR,vtx);
    if(L > nR || nL > R) return;
    if(L <= nL && nR <= R){
        lazy[vtx] += val;
        propagation(nL,nR,vtx);
        return;
    }
    int mid = (nL + nR)/2;
    f(L,R,vtx*2,nL,mid,val), f(L,R,vtx*2+1,mid+1,nR,val);
    arr[vtx] = arr[vtx*2] + arr[vtx*2+1];
}

int main(){
    int n,root,m,lv=1;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        scanf("%d",&root);
        if(root != -1) v[root].pb(i);
    }
    numbering(1);

    while(size < n){
        size += lv;
        lv *= 2;
    }

    int q,who,w;
    for(int i=0; i<m; i++){
        scanf("%d%d",&q,&who);
        int s = range[who].fst, e = range[who].snd;
        if(q == 1){
            scanf("%d",&w);
            f(s,e,1,1,size+1,w);
        }
        else{
            f(e,e,1,1,size+1,0);
            printf("%d\n",arr[size+e]);
        }
    }
}

