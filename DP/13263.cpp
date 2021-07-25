// 나무 자르기
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

lli A[100005], B[100005], n, dp[100005];
// dp[i] = dp[j]+b[j](a[i]-1) (1 <= j < i)
// a[i] = x라고 하면 b[j]x + dp[j]-b[j] 1차 함수로 표현 가능
// dp값을 i=1부터 차례대로 구하면 b[j], dp[j]는 이미 구한 값이기 때문에 상수로 표현됨.
// (i-1)개의 1차 함수를 그렸을 때 가장 아래에 그려지는 직선들을 찾아야 함.

vector<pair<double,pair<lli,lli> > > v; // b[j]x + dp[j]-B[j] 직선이 가장 최소가 되는 x의 시작점, b[j], dp[j]
// v에는 가장 아래에 그려지는 직선들만 남겨놓음
// b[j]는 점점 감소하기 때문에 새로 추가되는 직선들의 기울기도 점점 감소함. 그러므로
// v의 가장 마지막 직선과 새로운 직선의 교점이 마지막 직선의 시작점보다 앞에 있다면
// 새로운 직선이 마지막 직선의 시작점에서 더 아래에 있다는 뜻이므로 v에서 제외함 -> 시작점이 오름차순

// ax+b와 cx+d의 교점을 구하는 함수
double cross(lli a, lli b, lli c, lli d){
    //ax+b=cx+d -> (a-c)x = d-b, x=(d-b)/(a-c)
    return (double)(d-b)/(double)(a-c);
}

int main(){
    cinFast();
    cin >> n;

    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++) cin >> B[i];

    dp[1] = 0;
    v.pb(mp(0,mp(B[1], dp[1])));

    for(int i=2; i<=n; i++){
        //dp[i]값을 계산하기 위해 적절한 dp[j], b[j]를 구해야 함.
        //v에 들어있는 직선들 중에 x범위에 a[i]가 포함되는 직선을 이분탐색으로 구함
        int s = 0, e = v.size();
        while(s+1<e){
            int mid = (s+e)/2;
            if(v[mid].fst <= A[i]) s = mid; // 시작점이 A[i]보다 작은 것 중에 제일 큰 것
            else e = mid;
        }
        dp[i] = v[s].snd.fst*A[i] + v[s].snd.snd;

        //새로운 직선을 v에 추가
        while(v.size()){
            if(cross(B[i],dp[i], v.back().snd.fst,v.back().snd.snd) < v.back().fst) v.pop_back();
            else break;
        }
        v.pb(mp(cross(B[i], dp[i], v.back().snd.fst, v.back().snd.snd), mp(B[i],dp[i])));
    }

    cout << dp[n];
}
