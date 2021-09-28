//사이클 게임

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

struct Tree{
    vector<int> root;
    Tree(int n): root(n){
        for(int i=0; i<n; i++) root[i] = i;
    }

    int find_root(int n){
        if(root[n] == n) return n;
        return root[n] = find_root(root[n]);
    }

    void merge(int a, int b){
        int r1 = find_root(a);
        root[r1] = find_root(b);
    }

    bool isconnected(int a, int b){
        return find_root(a) == find_root(b);
    }
};

int main(){
    cinFast();
    int n,m;
    cin >> n >> m;

    Tree t(n);

    int ans = 0;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;

        if(ans) continue;
        if(t.isconnected(a,b)) ans = i+1;
        else t.merge(a,b);
    }
    cout << ans;
}
