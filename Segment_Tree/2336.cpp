#include <bits/stdc++.h>
using namespace std;

int sz = 1;
vector<int> tree(2000005,1e9);

void update(int idx, int val){
    tree[idx] = val;
    while(idx > 1){
        idx /= 2;
        tree[idx] = min(tree[idx*2], tree[idx*2+1]);
    }
}

int seg(int L, int R, int l, int r, int idx){
    if(L <= l && r <= R) return tree[idx];
    if(R < l || r < L) return 1e9;
    int mid = (l + r)/2;
    return min(seg(L,R,l,mid,idx*2), seg(L,R,mid+1,r,idx*2+1));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int,pair<int,int> > > v(n+1);
    for(int i=0, tmp; i<n; i++) cin >> tmp, v[tmp].first = i+1;
    for(int i=0, tmp; i<n; i++) cin >> tmp, v[tmp].second.first = i+1;
    for(int i=0, tmp; i<n; i++) cin >> tmp, v[tmp].second.second = i+1;

    sort(v.begin()+1, v.end());

    while(sz < n) sz *= 2;
    sz--;

    int ans = 0;
    for(int i=1; i<=n; i++){
        update(sz + v[i].second.first, v[i].second.second);
        int k = seg(1,v[i].second.first-1, 1, sz+1, 1);
        if(k > v[i].second.second) ans++; 
    }
    cout << ans << '\n';
}