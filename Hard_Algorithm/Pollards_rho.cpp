#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define pb push_back

struct Pollards_rho{
    vector<lli> prime_factor;
    vector<lli> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    void init(lli n){
        while(n > 1){
           lli tmp = rho(n);
           prime_factor.pb(n);
           n /= tmp;
        }
        sort(prime_factor.begin(), prime_factor.end());
    }

    void get_factor(){
        for(int i=0; i<prime_factor.size(); i++){
            cout << prime_factor[i] << '\n';
        }
    }

    /*  Deterministic Miller-Rabin (n < 2^64)
        return 1 if n is prime, 0 otherwise
    */
    bool miller_rabin(lli n){
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

    /*
        ai로 n이 합성수인지 테스트
        합성수이면 1, 아니면 0 return
    */
    bool isComposite(lli ai, lli q, lli k, lli n){
        lli tmp = 1; // tmp = ai^q mod n
        while(q > 0){
            if(q % 2) tmp = (tmp*ai) % n;
            tmp *= tmp;
            tmp %= n;
            q /= 2; 
        }
        // ai^q mod n 은 1이 아니고,
        // 0~k 사이의 자연수 i에 대해 ai^(2^iq) mod n이 n-1이 아니면 합성수
        if(tmp == 1 || tmp == n-1) return 0;

        for(int i=1; i<k; i++){
            tmp *= tmp;
            tmp %= n;
            if(tmp == n-1) return 0;
        }
        return 1;
    }

    lli gcd(lli a, lli b){
        if(a < b) swap(a, b);
        while(b != 0){
            lli tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }

    lli rho(lli n){
        if(miller_rabin(n)) return n;

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
        return rho(g);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    lli n;
    cin >> n;

    Pollards_rho a;
    a.init(n);
    a.get_factor();
}