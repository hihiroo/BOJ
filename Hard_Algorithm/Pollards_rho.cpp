#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define pb push_back

namespace Miller_Rabin{
    vector<lli> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    /*
        return a^b mod m
    */
    lli pow(lli a, lli b, lli m){
        if(b == 0) return 1;
        if(b % 2) return (a * pow(a, b-1, m)) % m;
        lli tmp = pow(a, b/2, m);
        return (tmp*tmp) % m;
    }
    /*
        ai로 n이 합성수인지 테스트
        합성수이면 1, 아니면 0 return
    */
    bool isComposite(lli ai, lli q, lli k, lli n){
        lli tmp = pow(ai, q, n); // tmp = ai^q mod n

        // ai^q mod n이 1이 아니고,
        // 0~k 사이의 자연수 i에 대해 ai^(2^iq) mod n이 n-1이 아니면 합성수
        if(tmp == 1 || tmp == n-1) return 0;

        for(int i=1; i<k; i++){
            tmp *= tmp;
            tmp %= n;
            if(tmp == n-1) return 0;
        }
        return 1;
    }
    /*  Deterministic Miller-Rabin (n < 2^64)
        return 1 if n is prime, 0 otherwise
    */
    bool isPrime(lli n){
        if(n == 2 || n == 3) return 1;
        if(n < 2 || n % 2 == 0) return 0;

        // n이 홀수이기 때문에 n-1 = 2^kq꼴로 나타낼 수 있음
        // 이때 q는 홀수
        lli k = 0, q = n-1;
        while(!(q & 1)){
            k++;
            q = q >> 1;
        }

        // A의 원소로 n이 합성수인지 테스트
        // 한 번이라도 합성수로 나오면 합성수
        for(int i=0; i<A.size() && A[i]<n-1; i++){
            if(isComposite(A[i], q, k, n)) return 0;
        }
        return 1;
    }
}

struct Pollards_rho{
    vector<lli> prime_factor;

    void init(lli n){
        factorize(n);
        sort(prime_factor.begin(), prime_factor.end());
    }

    lli gcd(lli a, lli b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    lli rho(lli n){
        lli x, y, c, g = 1;
        x = y = rand() % (n-2) + 2;
        c = rand() % 10 + 1;

        while(g == 1){
            x = ((x * x) % n + c) % n; // f(x) = x^2 + c mod n;
            y = ((y * y) % n + c) % n;
            y = ((y * y) % n + c) % n; // y는 두 번 이동
            g = gcd(abs(y-x), n);
            // g값이 1이 아니면 y-x가 0이거나 n의 인수 중 하나인 p의 배수.
            // 즉, y % p == x % p로 사이클 생김
            // birthday paradox에 의해 사이클을 찾는 시간복잡도는 O(sqrt(p))
        }
        return g;
    }

    void factorize(lli n){
        while(n % 2 == 0){
            prime_factor.pb(2);
            n /= 2;
        }
        if(n == 1) return;
        if(Miller_Rabin::isPrime(n)){
            prime_factor.pb(n);
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

    Pollards_rho a;
    a.init(n);
    for(int i=0; i<a.prime_factor.size(); i++){
        cout << a.prime_factor[i] << '\n';
    }
}