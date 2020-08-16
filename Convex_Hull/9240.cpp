//로버트 후드
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct P{
    double gx,gy;
    double x,y;
}p[100005];

bool cmp(P a, P b){
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(P a, P b){
    if(a.gy*b.gx != b.gy*a.gx)
        return a.gy*b.gx < b.gy*a.gx;

    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

double ccw(int a, int b, int c){
    //A = b-a, B = c-b;
    double ax = p[b].x - p[a].x;
    double ay = p[b].y - p[a].y;

    double bx = p[c].x - p[b].x;
    double by = p[c].y - p[b].y;

    return ax*by - ay*bx;
}

double dist(P a, P b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main(){
    cinFast();
    int c;
    cin >> c;

    for(int i=0; i<c; i++)
        cin >> p[i].x >> p[i].y;

    sort(p,p+c,cmp);

    for(int i=1; i<c; i++){
        p[i].gx = p[i].x - p[0].x;
        p[i].gy = p[i].y - p[0].y;
    }

    sort(p+1,p+c,cmp2);

    stack<int> s;
    s.push(0);
    s.push(1);
    int cur = 2;

    while(cur < c){
        while(s.size() >= 2){
            int b = s.top();
            s.pop();
            int a = s.top();

            if(ccw(a,b,cur) > 0){
                s.push(b);
                break;
            }
        }
        s.push(cur++);
    }

    vector<int> res;
    while(!s.empty()) res.pb(s.top()), s.pop();

    double ans = 0;
    for(int i=0; i<res.size(); i++){
        for(int j=i+1; j<res.size(); j++){
            ans = max(ans, dist(p[res[i]],p[res[j]]));
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << sqrt(ans);
}

