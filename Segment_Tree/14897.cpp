//서로 다른 수와 쿼리 1
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

vector<vector<int> > v(4000000);
map<int,int> m; // 바로 전에 나왔던 같은 수 인덱스
int size;

void construct(){
    for(int i=size; i>=1; i--){
        vector<int> &lv = v[i*2], &rv = v[i*2+1];
        int l = 0, r = 0, total = lv.size() + rv.size(), cnt = 0;
        v[i].resize(total);

        while(cnt < total){
            if(l == lv.size() || (r<rv.size() && rv[r]<lv[l])) v[i][cnt++] = rv[r++];
            else v[i][cnt++] = lv[l++];
        }
    }
}

// 이전 인덱스가 구간 시작점보다 작음 ==  구간에서 처음 등장한 수임
int f(int L, int R, int vtx, int nL, int nR){
    if(nR < L || nL > R) return 0;
    if(L <= nL && nR <= R) return lower_bound(v[vtx].begin(), v[vtx].end(), L) - v[vtx].begin();

    int mid = (nL + nR)/2;
    return f(L,R,vtx*2,nL,mid) + f(L,R,vtx*2+1,mid+1,nR);
}

int main(){
    cinFast();
    int n, lv=1;
    cin >> n;

    while(size+1 < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        v[size+i].pb(m[a]);
        m[a] = i;
    }

    construct();

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;

        cout << f(a,b,1,1,size+1) << '\n';
    }
}
