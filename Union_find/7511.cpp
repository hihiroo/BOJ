//소셜 네트워킹 어플리케이션
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


struct A{
    vector<int> root;
    A(int n): root(n+1){
        for(int i=0; i<=n; i++)
            root[i] = i;
    }
    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }
    bool connect(int a, int b){
        int r1 = find(a), r2 = find(b);
        return r1 == r2;
    }
    void merge(int a, int b){
        int r1 = find(a), r2 = find(b);
        root[r2] = r1;
    }
};

int main(){
    int t;
    cin>>t;
    for(int p=1; p<=t; p++){
        int n,k,m;
        cin>>n>>k;
        A gr(n);
        for(int i=1; i<=k; i++){
            int s,f;
            scanf("%d%d",&s,&f);
            if(!gr.connect(s,f)) gr.merge(s,f);
        }
        cin>>m;
        cout<<"Scenario "<<p<<":\n";
        for(int i=0; i<m; i++){
            int s,f;
            scanf("%d%d",&s,&f);
            if(gr.connect(s,f)) printf("1\n");
            else printf("0\n");
        }
        cout<<'\n';
    }
}
