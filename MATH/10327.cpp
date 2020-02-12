//피보나치 문제해결전략
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef pair<lli,pair<lli,lli> > p3;

lli dp[45] = {1,1}, INF = 1000000000, g;

p3 exGcd(lli a, lli b){
    if(b == 0) return mp(a,mp(1,0));
    p3 temp = exGcd(b,a%b);
    lli x = temp.snd.fst, y = temp.snd.snd;
    return mp(temp.fst,mp(y,x-(a/b)*y));
}

int main(){
    for(int i=2; i<45; i++)
        dp[i] = dp[i-1]+dp[i-2];

    int t;
    cin>>t;
    for(; t>0; t--){
        pair<lli, lli> ans = mp(INF,INF);
        cin>>g;

        for(int i=1; dp[i]<g; i++){
            lli a = dp[i-1], b = dp[i];
            p3 ret = exGcd(a,b);
            lli x = ret.snd.fst, y = ret.snd.snd;
            x *= g, y *= g;

            if(x <= 0){// x+bk <= y-ak
                //(a+b)k <= (y-x)
                lli k = (y-x)/(a+b);
                y -= a*k, x += b*k;
            }
            else if(y <= 0){// x-bk <= y+ak
                // x-y <= (a+b)k
                lli k = (x-y)/(a+b)+1;
                if((x-y)%(a+b) == 0) k--;
                x -= b*k, y += a*k;
            }
            if(x <= 0) continue;
            if(mp(x,y) < ans) ans = mp(x,y);
        }
        cout<<ans.fst<<" "<<ans.snd<<'\n';
    }
}
