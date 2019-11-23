#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

struct U{
    vector<int> root;
    U(int n) : root(n + 1){
        for (int i = 1; i <= n; i++)
            root[i] = i;
    }
    int find_root(int n){
        if (root[n] == n)
            return n;
        return root[n] = find_root(root[n]);
    }
    void mg(int a, int b){
        int r1 = find_root(a);
        int r2 = find_root(b);
        root[r2] = r1;
    }
    bool connect(int a, int b){
        return find_root(a) == find_root(b);
    }
};

int main(){
    int n, m, cn;
    cin >> n >> m;
    U city(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> cn;
            if (cn) city.mg(i, j);
        }
    }
    bool chk = false;
    int pre, next;
    cin >> pre;
    for (int i = 1; i < m; i++){
        cin >> next;
        if (chk) continue;
        if (!city.connect(pre, next)) chk = true;
        pre = next;
    }
    if (chk)
        printf("NO");
    else
        printf("YES");
}
