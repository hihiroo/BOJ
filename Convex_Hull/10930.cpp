//Wall construction
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
}v[1005];

bool cmp(P a, P b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(P a, P b){//a.p/a.q < b.p/b.q
    if(a.p*b.q != a.q*b.p)
        return a.p*b.q < a.q*b.p;
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool ccw(P v1, P v2, P v3){//v1v3 > v1v2(반시계)
    return (v3.y-v1.y)*(v2.x-v1.x) > (v3.x-v1.x)*(v2.y-v1.y);
}

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int n;
    double r, sum;
    cin>>n>>r;
    sum = 2*3.14159265359*r;
    for(int i=0; i<n; i++)
        scanf("%lld%lld",&v[i].x,&v[i].y);
    sort(v,v+n,cmp);
    for(int i=1; i<n; i++){
        v[i].p = v[i].y - v[0].y;
        v[i].q = v[i].x - v[0].x;
    }
    sort(v+1,v+n,cmp2);

    stack<int> s;
    s.push(0), s.push(1);
    int next = 2;
    while(next < n){
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
    double pre_y = v[s.top()].y;
    double pre_x = v[s.top()].x;
    sum += dis((double)v[0].x,(double)v[0].y, pre_x, pre_y);
    s.pop();

    while(!s.empty()){
        double y = (double)v[s.top()].y;
        double x = (double)v[s.top()].x;
        s.pop();
        sum += dis(pre_x, pre_y, x, y);
        pre_y = y, pre_x = x;
    }
    printf("%.8lf",sum);
}