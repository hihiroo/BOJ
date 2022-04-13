#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long

namespace MillerRabin{
    lli add(lli a, lli b, lli m){
        a %= m;
        b %= m;
        if(a >= m-b) return a-(m-b);
        return a+b;
    }
    lli mul(lli a, lli b, lli m){
        lli res = 0;
        while(b > 0){
            if(b & 1) res = add(res, a, m);
            b = b >> 1;
            a = add(a, a, m);
        }
        return res;
    }
    lli pow(lli a, lli b, lli m){
        lli res = 1;
        while(b > 0){
            if(b & 1) res = mul(res, a, m);
            b = b >> 1;
            a = mul(a, a, m);
        }
        return res;
    }
    bool isComposite(lli ai, lli q, lli k, lli n){
        lli tmp = pow(ai, q, n);
        if(tmp == 1 || tmp == n-1) return 0;

        for(int i=1; i<k; i++){
            tmp = mul(tmp, tmp, n);
            if(tmp == n-1) return 0;
        }
        return 1;
    }
    bool isPrime(lli n){
        if(n == 2) return 1;
        if(n < 2 || n % 2 == 0) return 0;

        lli k = 0, q = n-1;
        while(!(q & 1)){
            k++;
            q = q >> 1;
        }

        vector<int> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(int i=0; i<A.size() && A[i]<n-1; i++){
            if(isComposite(A[i], q, k, n)) return 0;
        }
        return 1;
    }
}

struct PollardsRho{
    vector<int> primeFactor;

    PollardsRho(lli n): primeFactor(0){
        factorize(n);
        sort(primeFactor.begin(), primeFactor.end());
    }

    lli gcd(lli a, lli b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    lli rho(lli n){
        if(n % 2 == 0) return 2;

        lli x, y, c, g = 1;
        x = y = rand() % (n-2) + 2;
        c = rand() % 10 + 1;

        while(g == 1){
            x = (MillerRabin::mul(x, x, n) + c) % n;
            y = (MillerRabin::mul(y, y, n) + c) % n;
            y = (MillerRabin::mul(y, y, n) + c) % n;
            g = gcd(abs(x-y), n);
        }
        return g;
    }
    void factorize(lli n){
        if(n == 1) return;
        if(MillerRabin::isPrime(n)){
            primeFactor.pb(n);
            return;
        }
        lli tmp = rho(n);
        factorize(tmp), factorize(n/tmp);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    lli n;
    cin >> n;

    PollardsRho a(n);

    lli ans = 1, cnt = 0;
    for(int i=0; i<a.primeFactor.size(); i++){
        if(i && a.primeFactor[i-1] != a.primeFactor[i]){
            ans *= (cnt+1);
            cnt = 0;
        }
        cnt++;
    }
    ans *= (cnt+1);

    cout << ans;
}