//리모컨
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int ban[10],ans,n;

void f(int now, int lv){
    if(lv > 6) return;
    ans = min(ans,abs(now-n)+lv);

    for(int i=0; i<=9; i++)
        if(!ban[i]) f(now*10+i,lv+1);
}

int main(){
    int m,a;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a;
        ban[a] = 1;
    }

    ans = abs(100-n);
    for(int i=0; i<=9; i++){
        if(!ban[i]) f(i,1);
    }
    cout<<ans;
}
