//편안한 수열 만들기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    int n,k;
    cin>>n>>k;
    if(n == 3) return cout<<"NO",0;
    else cout<<"YES"<<'\n';

    if(n == 2){
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2;
    }
    else if(k == n-1){
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"reverse "<<1<<" "<<k<<'\n';
        cout<<"swap "<<1<<" "<<n<<'\n';
        cout<<"reverse "<<2<<" "<<k;
    }
    else if(k == 1){
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"reverse "<<2<<" "<<n<<'\n';
        cout<<"swap "<<1<<" "<<n<<'\n';
        cout<<"reverse "<<2<<" "<<n-1;
    }
    else{
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"swap "<<1<<" "<<2<<'\n';
        cout<<"reverse "<<1<<" "<<n<<'\n';
        cout<<"reverse "<<1<<" "<<n-k<<'\n';
        cout<<"reverse "<<n-k+1<<" "<<n;
    }
}
