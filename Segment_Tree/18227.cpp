//성대나라의 물탱크
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > v(200005);
pair<int,int> range[200005];

int cnt, size;
lli arr[800000],lv[200005];

void numbering(int vtx, int level){
    range[vtx].fst = cnt+1;
    lv[vtx] = level;

    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(range[next].fst == 0)
            numbering(next,level+1);
    }

    range[vtx].snd = ++cnt;
}

void update(int idx){
    arr[idx]++;
    while(idx > 1){
        idx /= 2;
        arr[idx] = arr[idx*2] + arr[idx*2+1];
    }
}

lli f(int L, int R, int vtx, int nL, int nR){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL + nR)/2;
    return f(L,R,vtx*2,nL,mid)+f(L,R,vtx*2+1,mid+1,nR);
}

int main(){
    int n,root, k = 1;
    cin>>n>>root;

    for(int i=1; i<n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].pb(b), v[b].pb(a);
    }

    numbering(root,1);

    while(size < n){
        size += k;
        k *= 2;
    }

    int q, t, a;
    cin>>q;

    for(; q>0; q--){
        scanf("%d%d",&t,&a);
        if(t == 2)
            printf("%lld\n",f(range[a].fst,range[a].snd,1,1,size+1)*lv[a]);
        else update(size+range[a].snd);
    }
}
