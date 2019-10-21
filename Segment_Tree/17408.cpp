//수열과 쿼리 24

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

int size, cmp[4];
vector<pair<int,int> > v(400005);

void construct(){
    for(int i=size; i>0; i--){
        cmp[0] = v[i*2].fst, cmp[1] = v[i*2+1].fst;
        cmp[2] = v[i*2].snd, cmp[3] = v[i*2+1].snd;
        sort(cmp,cmp+4);
        v[i] = mp(cmp[3],cmp[2]);
    }
}

void update(int i, int val){
    i += size;
    v[i].fst = val;

    while(i > 1){
        i /= 2;
        cmp[0] = v[i*2].fst, cmp[1] = v[i*2+1].fst;
        cmp[2] = v[i*2].snd, cmp[3] = v[i*2+1].snd;
        sort(cmp,cmp+4);
        v[i] = mp(cmp[3],cmp[2]);
    }
}

pair<int,int> f(int L, int R, int vtx, int nL, int nR){
    if(R < nL || L > nR) return mp(0,0);
    if(L <= nL && nR <= R) return v[vtx];
    int mid = (nL + nR)/2;
    pair<int,int> a,b;
    a = f(L,R,vtx*2,nL,mid);
    b = f(L,R,vtx*2+1,mid+1,nR);
    cmp[0] = a.fst, cmp[1] = a.snd, cmp[2] = b.fst, cmp[3] = b.snd;
    sort(cmp,cmp+4);
    return mp(cmp[3],cmp[2]);
}

int main(){
    int n,lv=1;
    scanf("%d",&n);

    while(lv < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++)
        scanf("%d",&v[i+size].fst);

    construct();

    int m,q,a,b;
    scanf("%d",&m);

    for(int i=0; i<m; i++){
        scanf("%d%d%d",&q,&a,&b);
        if(q == 1) update(a,b);
        else{
            pair<int,int> res;
            res = f(a,b,1,1,size+1);
            printf("%d\n",res.fst + res.snd);
        }
    }
}


