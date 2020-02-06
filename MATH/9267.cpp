//A+B
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef pair<lli,pair<lli,lli> > pp;

pp exGcd(lli a, lli b){
    if(b == 0) return mp(a,mp(1,0));
    pp tmp = exGcd(b,a%b);
    lli x = tmp.snd.fst, y = tmp.snd.snd;
    return mp(tmp.fst,mp(y,x-(a/b)*y));
}

int main(){
    lli a,b,s;
    cin>>a>>b>>s;
    if(a == s || b == s) return cout<<"YES",0;
    else if(a > s && b > s) return cout<<"NO",0;
    else if(a == 0 || b == 0){
        if(!a && !b) cout<<"NO",0;
        else if(a == 0 && s % b == 0) cout<<"YES",0;
        else if(b == 0 && s % a == 0) cout<<"YES",0;
        else cout<<"NO",0;
        return 0;
    }
    
    pp ret = exGcd(a,b);
    lli gcd = ret.fst; 
    if(s % gcd) return cout<<"NO",0;
    lli x = (s/gcd)*ret.snd.fst, y = (s/gcd)*ret.snd.snd;
    //a0x' + b0y' = gcd(a0,b0);
    //a0x + b0y = S
    //a0*q = b0*t 이고, a0x-a0q*k + b0x+b0t*k = S
    lli q = b/gcd, t = a/gcd;
    

    if(x >= 0 && y >= 0) return cout<<"YES",0;
    if(x >= 0){ // y<0, x-qk>=0, x/q>=k
        lli max_k = x/q;
        if(t >= -y/max_k) return cout<<"YES",0;
        else return cout<<"NO",0;
    }
    else{ // y >= 0, x<0
        lli max_k = y/t;
        if(q >= -x/max_k) return cout<<"YES",0;
        else return cout<<"NO",0;
    }
}

