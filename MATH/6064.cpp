//카잉 달력
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>m>>n>>x>>y;

        int k = n*m/gcd(n,m);

        if(x == m) x = 0;
        if(y == n) y = 0;

        bool poss = false;
        for(int i=x; i<=k; i+=m){
            if(i%n == y){
                printf("%d\n",i);
                poss = true;
                break;
            }
        }

        if(!poss) printf("-1\n");
    }
}

