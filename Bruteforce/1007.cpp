//벡터매칭
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<pair<lli,lli> > v;
double ans;
lli sum_x, sum_y, n;

void f(int idx, int cnt, lli sumX, lli sumY){
    if(cnt == n/2){
        lli X = sumX - (sum_x - sumX);
        lli Y = sumY - (sum_y - sumY);

        double len = sqrt(double(X*X + Y*Y));;
        ans = min(ans, len);
    }
    if(idx == n) return;
    f(idx+1, cnt, sumX, sumY);
    f(idx+1, cnt+1, sumX+v[idx].fst, sumY+v[idx].snd);
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        cin>>n;
        v.clear(), ans = 1e8;
        sum_x = 0, sum_y = 0;

        lli x, y;
        for(int i=0; i<n; i++){
            scanf("%lld%lld",&x, &y);
            sum_x += x, sum_y += y;
            v.pb(mp(x,y));
        }
        f(0,0,0,0);
        printf("%.6lf\n",ans);
    }
}
