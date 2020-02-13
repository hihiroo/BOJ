//트리의 순회
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int in[100005], post[100005], idx[100005];

void f(int iS, int iE, int pS, int pE){
    if(iS > iE || pS > pE) return;
    int root = post[pE];
    printf("%d ",root);

    f(iS,idx[root]-1,pS,pS+(idx[root]-1-iS));
    f(idx[root]+1,iE,pS+idx[root]-iS,pE-1);
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        idx[in[i]] = i;
    }
    for(int i=1; i<=n; i++) scanf("%d",&post[i]);
    f(1,n,1,n);
}


