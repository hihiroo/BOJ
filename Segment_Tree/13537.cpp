//수열과 쿼리1
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<vector<int> > arr(400005);
int size;

void construct(){
    for(int i=size; i>=1; i--){
        for(int j=0; j<arr[i*2].size(); j++)
            arr[i].pb(arr[i*2][j]);
        for(int j=0; j<arr[i*2+1].size(); j++)
            arr[i].pb(arr[i*2+1][j]);
        sort(arr[i].begin(),arr[i].end());
    }
}

int solve(int L,int R,int vtx,int nL,int nR,int k){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R){
        int idx = upper_bound(arr[vtx].begin(),arr[vtx].end(),k)-arr[vtx].begin();
        return arr[vtx].size()-idx;
    }
    int mid = (nL + nR)/2;
    return solve(L,R,vtx*2,nL,mid,k)+solve(L,R,vtx*2+1,mid+1,nR,k);
}

int main(){
    int n, lv = 1, m;
    cin >> n;
    while(size < n){
        size += lv;
        lv *= 2;
    }

    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        arr[size+i].pb(a);
    }

    construct();

    cin >> m;
    while(m--){
        int s,f,k;
        scanf("%d%d%d",&s,&f,&k);
        printf("%d\n",solve(s,f,1,1,size+1,k));
    }
}
