// 해의 개수
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

#define p3 pair<lli, pair<lli,lli> >
// ax+by = gcd(a,b)
// a = bq + r (q = a/b, r = a%b)
// (bq+r)x + by = (qx+y)b + rx = gcd(b,r)
// qx+y = x', x = y'라고 하자.
// y = x'-qx = x'-qy' = x'-(a/b)y'
p3 exgcd(lli a, lli b){
    if(b == 0) return mp(a,mp(1,0)); // b=0이므로 ax = gcd(a,b) = a. x=1
    p3 tmp = exgcd(b,a%b);
    lli xx = tmp.snd.fst, yy = tmp.snd.snd;
    return mp(tmp.fst, mp(yy, xx-(a/b)*yy));
}

lli divide(lli a, lli b){
    lli ak=1, bk=1;
    if(a < 0) ak = -1;
    if(b < 0) bk = -1;
    return ak*bk*abs(a)/abs(b);
}

int main(){
    lli A, B, C, x1, x2, y1, y2;
    cin >> A >> B >> C >> x1 >> x2 >> y1 >> y2;

    if(A == 0 && B == 0){
        if(C == 0) return cout << (x2-x1+1)*(y2-y1+1),0;
        else return cout << 0,0;
    }
    else if(A == 0){
        if(abs(C)%abs(B) || !(y1 <= divide(-C,B) && divide(-C,B) <= y2)) return cout << 0,0;
        else return cout << (x2-x1+1),0;
    }
    else if(B == 0){
        if(abs(C)%abs(A)|| !(x1 <= divide(-C,A) && divide(-C,A) <= x2)) return cout << 0,0;
        else return cout << (y2-y1+1),0;
    }

    p3 res = exgcd(A,B);
    lli gcd = res.fst, x0 = res.snd.fst, y0 = res.snd.snd;
    // Ax0 + By0 = gcd

    // -C/gcd(Ax0+By0) = -C
    if(abs(C)%abs(gcd)) return cout << 0, 0;
    x0 = divide(-x0*C,gcd), y0 = divide(-y0*C,gcd);

    // a(x+k)+by-ak = C
    // a(x+k)+b(y-ak/b) = C, ak가 b의 배수여야 함
    // ab/gcd가 최소공배수이므로 k=b/gcd
    lli k = abs(B)/abs(gcd), ans = 0, x = x0, y = y0;

    while(x <= x2){
        if(x1 <= x && y1 <= y && y <= y2) ans++;
        x += k, y -= divide(A*k,B);
    }

    x = x0, y = y0;
    while(x1 <= x){
        if(x <= x2 && y1 <= y && y <= y2) ans++;
        x -= k, y += divide(A*k,B);
    }

    if(x1 <= x0 && x0 <= x2 && y1 <= y0 && y0 <= y2) ans--;
    cout << ans;
}
