//수열과 쿼리3

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


int size;
vector<vector<int> > v(400005);

void construct(){
    for(int i=size; i>0; i--){
        for(int j=0; j<v[i*2].size(); j++)
            v[i].pb(v[i*2][j]);
        for(int j=0; j<v[i*2+1].size(); j++)
            v[i].pb(v[i*2+1][j]);
        sort(v[i].begin(),v[i].end());
    }
}

int f(int L, int R, int vtx, int nL, int nR, int k){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R){
        int idx = upper_bound(v[vtx].begin(),v[vtx].end(),k)-v[vtx].begin();
        return v[vtx].size()-idx;
    }
    int mid = (nL + nR)/2;
    return f(L,R,vtx*2,nL,mid,k)+f(L,R,vtx*2+1,mid+1,nR,k);
}

int main(){
    int n, lv=1;
    scanf("%d",&n);

    while(lv < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        v[size+i].pb(a);
    }

    construct();
    int m,a,b,c,last_ans;
    scanf("%d",&m);

    for(int i=0; i<m; i++){
        scanf("%d%d%d",&a,&b,&c);
        if(i){
            a ^= last_ans;
            b ^= last_ans;
            c ^= last_ans;
        }
        last_ans = f(a,b,1,1,size+1,c);
        printf("%d\n",last_ans);
    }
}


