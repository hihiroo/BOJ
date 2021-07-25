// 특공대
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

lli sum[1000005], a, b, c, dp[1000005];
// dp[i] = max(A[i]B[j]+C[j])+D[i]
// i번째까지 얻을 수 있는 조정된 최대 전투력
vector<pair<double,int> > v; // 시작점, 인덱스

lli A(int i){
    return -2*a*sum[i];
}

lli B(int j){
    return sum[j];
}

lli C(int j){
    return a*sum[j]*sum[j]-b*sum[j]+dp[j];
}

lli D(int i){
    return a*sum[i]*sum[i]+b*sum[i]+c;
}

double cross(lli a, lli b, lli c, lli d){
    //ax+b = cx+d -> x = (d-b)/(a-c)
    return (double)(d-b)/(double)(a-c);
}

int main(){
    cinFast();
    int n;
    cin >> n;

    cin >> a >> b >> c;
    for(int i=1; i<=n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    dp[0] = 0;
    v.pb(mp(0,0));

    for(int i=1; i<=n; i++){
        //x=A[i], x를 포함하는 직선 찾기
        int s=0, e=v.size();
        while(s+1<e){
            int mid=(s+e)/2;
            if(v[mid].fst <= A(i)) s = mid;
            else e = mid;
        }
        int j = v[s].snd;
        dp[i] = A(i)*B(j)+C(j)+D(i);
       
        while(v.size()){
            if(cross(B(i),C(i),B(v.back().snd),C(v.back().snd)) < v.back().fst) v.pop_back();
            else break;
        }
        v.pb(mp(cross(B(i),C(i),B(v.back().snd),C(v.back().snd)), i));
    }
    cout << dp[n];
}
