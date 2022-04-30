// 지민이의 테러
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define P pair<lli,lli>
using namespace std;

int ccw(P a, P b, P c){ // ab.x*bc.y - ab.y*bc.x
    lli tmp = (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
    if(tmp == 0) return 0;
    if(tmp < 0) return -1;
    return 1;
}

bool isCross(P a, P b, P c, P d){ // ab, cd
    int abc = ccw(a,b,c), abd = ccw(a,b,d);
    int cda = ccw(c,d,a), cdb = ccw(c,d,b);

    if(abc*abd == 0 && cda*cdb == 0){
        if(a > b) swap(a,b);
        if(c > d) swap(c,d);
        if(a <= d && c <= b) return 1;
        return 0;
    }
    if(abc*abd <= 0 && cda*cdb <= 0) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<P> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].x >> v[i].y;
    }
    v.pb(v[0]);

    for(int i=0; i<3; i++){
        P friends;
        cin >> friends.x >> friends.y;

        int cross = 0, online = 0;
        for(int j=0; j<n && !online; j++){
            online = isCross(v[j], v[j+1], friends, friends);
            if(isCross(v[j], v[j+1], friends, {1e9+1, friends.y})){
                cross++;
                if(v[j].y == v[j+1].y) cross++;
            }
        }

        if(online) cout << 1 << '\n';
        else cout << cross << '\n';
    }
}

