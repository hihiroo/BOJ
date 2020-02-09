//세진이의 미팅
#include <bits/stdc++.h>
using namespace std;

long long int gs(long long int a,long long int p){
    if(p==0) return 1;
    if(p%2==1) return (a*gs(a,p-1))%1000000007;
    long long int k=gs(a,p/2);
    return (k*k)%1000000007;
}

int main(){
    long long int n,m;
    cin>>n>>m;
    m=min(m,n-m);

    long long int fac=1,t=1;
    for(long long int i=n;i>n-m;i--) fac=(fac*i)%1000000007;

    for(long long int i=2;i<=m;i++) t=(t*i)%1000000007;

    printf("%lld",(fac*gs(t,1000000005))%1000000007);

}
