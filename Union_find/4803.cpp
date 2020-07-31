//트리
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct A{
    vector<int> root;
    A(int n): root(n+1){
        for(int i=1; i<=n; i++)
            root[i] = i;
    }

    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }

    void merge(int a, int b){
        int r1 = find(a);
        root[r1] = find(b);
    }

    bool connect(int a, int b){
        return find(a) == find(b);
    }
};

int main(){
    cinFast();

    int n,m,t=0;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        A g(n);
        vector<int> isTree(n+1,1);

        for(int i=1; i<=m; i++){
            int a,b;
            cin >> a >> b;
            if(g.connect(a,b)) isTree[a] = 0;
            else g.merge(a,b);
        }

        for(int i=1; i<=n; i++)
            if(!isTree[i]) isTree[g.find(i)] = 0;

        int ans = 0;
        for(int i=1; i<=n; i++)
            if(g.find(i) == i && isTree[i]) ans++;

        cout << "Case " << ++t << ": ";
        if(ans == 0) cout << "No trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}
