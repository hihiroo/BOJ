//Convex Hull
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


struct P{
    lli x,y;
    lli p,q;
}point[100005];


bool cmp(P a, P b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(P a, P b){
    if(a.q*b.p != a.p*b.q)
        return a.q*b.p < a.p*b.q;
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main(){
    int n,size = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        lli x,y;
        char isY;
        scanf(" %lld %lld %c",&x,&y,&isY);
        if(isY == 'N') continue;
        point[size].x = x, point[size++].y = y;
    }
    sort(point,point+size,cmp);
    for(int i=1; i<size; i++){
        point[i].p = point[i].x-point[0].x;
        point[i].q = point[i].y-point[0].y;
    }
    sort(point+1,point+size,cmp2);
    cout<<size<<'\n';
    for(int i=0; i<size; i++){
        cout<<point[i].x<<" "<<point[i].y<<'\n';
    }
}
