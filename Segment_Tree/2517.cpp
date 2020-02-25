#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int size, arr[2000005], q[500000];
map<int,int> hasing;
vector<int> v;

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

    for(int i=0; i<n; i++){
        scanf("%d",&q[i]);
        v.pb(q[i]);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()),v.end());

    int cnt = v.size();
    for(int i=0; i<cnt; i++)
        hasing[v[i]] = i+1;

    while(size < cnt){
        size += lv;
        lv *= 2;
    }

    for(int i=0; i<n; i++){
        printf("%d\n",f(hasing[q[i]],cnt,1,1,size+1)+1);
        update(size+hasing[q[i]]);
    }
}
