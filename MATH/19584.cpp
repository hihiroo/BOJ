//난개발
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<lli,lli> de;//y좌표가 몇 번째로 큰지
lli include[200005];

int main(){
    cinFast();
    lli n,m;
    cin >> n >> m;

    vector<lli> y, pos(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        y.pb(b), pos[i] = b;
    }

    sort(y.begin(),y.end());//y좌표 압축
    y.erase(unique(y.begin(),y.end()),y.end());

    for(lli i=0; i<y.size(); i++) de[y[i]] = i+1;

    //두 y좌표 중 작은 값을 k, 큰 값을 q 라고 하면
    //k~끝까지 c를 포함, q+1~끝까지 -c를 포함한다고 생각 할 수 있음
    for(lli i=0; i<m; i++){
        lli a,b,c;
        cin >> a >> b >> c;

        lli k = min(de[pos[a-1]],de[pos[b-1]]);
        lli q = max(de[pos[a-1]],de[pos[b-1]]);

        include[k] += c;
        include[q+1] -= c;
    }

    //1부터 y좌표 끝까지 누적 합을 구하면 
    //얼마나 중첩되어있는지 알 수 있음.
    lli ans = include[1];
    for(lli i=2; i<=y.size(); i++){
        include[i] += include[i-1];
        ans = max(ans,include[i]);
    }
    cout << ans;
}
