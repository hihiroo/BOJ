//친구비
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct U{
    vector<int> root;
    U(int n): root(n+1){
        for(int i=1; i<=n; i++)
            root[i] = i;
    }
    int find_root(int n){
        if(root[n] == n) return n;
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
map<int,int> money;
int main(){
    int n,m,k,s,f,arr[10001];
    cin>>n>>m>>k;
    U fri(n);
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    for(int i=1; i<=m; i++){
        cin>>s>>f;
        fri.mg(s,f);
    }

    for(int i=1; i<=n; i++){
        int component = fri.find_root(i);
        if(money.find(component) == money.end())
            money[component] = arr[i];
        else money[component] = min(arr[i],money[component]);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        int component = fri.find_root(i);
        cnt += money[component];
        money[component] = 0;
    }
    if(cnt > k) printf("Oh no");
    else printf("%d",cnt);
}
