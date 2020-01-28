//감옥건설
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct P{
    lli y, x;
    lli p, q;
    int idx;
}point[1005];

bool cmp(P a, P b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(P a, P b){//a.p/a.q < b.p/b.q 순으로
    if(a.p*b.q != a.q*b.p)
        return a.p*b.q < a.q*b.p;
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool ccw(P v1, P v2, P v3){//v3가 v1v2왼쪽에 있는지
//(v3.y-v1.y)/(v3.x-v1.x) > (v2.y-v1.y)/(v2.x-v2.x)
    return (v2.x-v1.x)*(v3.y-v1.y) > (v2.y-v1.y)*(v3.x-v1.x);
}

int finish[1005];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        scanf("%lld%lld",&point[i].x, &point[i].y);
        point[i].idx = i;
    }

    vector<P> v;
    int ans = 0;
    while(1){
        v.clear();
        for(int i=0; i<=n; i++){
            if(finish[point[i].idx]) continue;
            v.pb(point[i]);
        }
        if(v.size() <= 2) break;
        sort(v.begin(),v.end(),cmp);

        for(int i=1; i<v.size(); i++){
            v[i].p = v[i].y-v[0].y;
            v[i].q = v[i].x-v[0].x;
        }
        sort(v.begin()+1,v.end(),cmp2);

        stack<int> s;
        s.push(0);
        s.push(1);
        int next = 2;
        while(next < v.size()){
            while(s.size() >= 2){
                int v2 = s.top();
                s.pop();
                int v1 = s.top();
                if(ccw(v[v1],v[v2],v[next])){
                    s.push(v2);
                    break;
                }
            }
            s.push(next++);
        }
        while(!s.empty()){
            int vtx = s.top();
            s.pop();
            if(v[vtx].idx == 0)
                return cout<<ans,0;
            finish[v[vtx].idx] = 1;
        }
        ans++;
    }
    cout<<ans;
}
