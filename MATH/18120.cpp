// 대농부 김상혁
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct P{
    double y, x, w;
    double dist;
    void calc(){
        dist = sqrt(y*y + x*x);
    }
}p[100005];

bool cmp(P a, P b){
    return a.dist < b.dist;
}

double wsum[100005], wdist[100005];

int main(){
    cinFast();
    int N,A;
    cin >> N >> A;

    for(int i=1; i<=N; i++){
        cin >> p[i].y >> p[i].x >> p[i].w;
        p[i].calc();
    }

    sort(p+1,p+N+1,cmp);

    for(int i=1; i<=N; i++){
        wsum[i] = wsum[i-1] + p[i].w;
        wdist[i] = wdist[i-1] + p[i].w*p[i].dist;
    }

    double ans = 0;
    for(int i=1; i<=N; i++){
        double r = wsum[i]/(2*(double)A);

        double inc = 0;
        if(r < p[i].dist) r= p[i].dist;

        inc = -(double)A*r*r + r*wsum[i] - wdist[i];
        ans = max(ans,inc);
    }

    cout << fixed;
    cout.precision(6);
    cout << ans;
}
