//회사 문화5
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
int cnt = 0, off[400005], lazy[400005], size;

void post(int vtx){
    range[vtx].fst = cnt+1;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        post(next);
    }
    range[vtx].snd = cnt++;
}

void propagation(int nL, int nR, int vtx){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] = lazy[vtx];
            lazy[vtx*2+1] = lazy[vtx];
        }
        off[vtx] = (lazy[vtx]-1)*(nR-nL+1);
        lazy[vtx] = 0;
    }
}

void f(int L, int R, int vtx, int nL, int nR, int q){
    propagation(nL,nR,vtx);
    if(nR < L || nL > R) return;
    if(L <= nL && nR <= R){
        lazy[vtx] = q;
        propagation(nL,nR,vtx);
        return;
    }
    int mid = (nL + nR)/2;
    f(L,R,vtx*2,nL,mid,q), f(L,R,vtx*2+1,mid+1,nR,q);
    off[vtx] = off[vtx*2] + off[vtx*2+1];
}

int sum(int L,int R, int vtx, int nL, int nR){
    propagation(nL,nR,vtx);
    if(nR < L || nL > R) return 0;
    if(L <= nL && nR <= R) return off[vtx];
    int mid = (nL + nR)/2;
    return sum(L,R,vtx*2,nL,mid)+sum(L,R,vtx*2+1,mid+1,nR);
}

int main(){
    int n, m, lv = 1;
    cin>>n;
    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++){
        int root;
        scanf("%d",&root);
        v[root].pb(i);
    }
    post(1);

    cin>>m;
    for(; m>0; m--){
        int q, i, s, e;
        scanf("%d%d",&q,&i);
        s = range[i].fst, e = range[i].snd;
        if(q <= 2){
            if(s > e) continue;
            f(s,e,1,1,size+1,q);
        }
        else{
            if(s > e) printf("0\n");
            else{
                int cnt = e-s+1;
                printf("%d\n",cnt-sum(s,e,1,1,size+1));
            }
        }
    }
}

