// 집합의 표현

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

struct A{
    vector<int> root;
    A(int n): root(n+1){
        for(int i=1; i<=n; i++){
            root[i]=i;
        }
    }
    int find_root(int n){
        if(root[n] == n) return n;
        return root[n] = find_root(root[n]);
    }
    void merge(int a, int b){
        int ar = find_root(a);
        int br = find_root(b);
        root[br] = ar;
    }
    bool connect(int a, int b){
        return find_root(a) == find_root(b);
    }
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    A uni(n);
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0) uni.merge(b,c);
        else{
            if(uni.connect(b,c)) printf("YES\n");
            else printf("NO\n");
        }
    }
}



