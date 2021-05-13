//선분 교차2
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

#define pt pair<int,int>

int ccw(pt a, pt b, pt c){
    lli res = 1LL*(b.fst-a.fst)*(c.snd-b.snd);
    res -= 1LL*(b.snd-a.snd)*(c.fst-b.fst);
    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}

int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pt A = {x1,y1}, B = {x2,y2}, C = {x3,y3}, D = {x4,y4};
    int abc = ccw(A,B,C);
    int abd = ccw(A,B,D);
    int cda = ccw(C,D,A);
    int cdb = ccw(C,D,B);

    if(abc*abd == 0 && cda*cdb == 0){
        if(A>B) swap(A,B);
        if(C>D) swap(C,D);
        if(A<=D && C<=B) return cout << 1,0;
        return cout << 0,0;
    }
    if(abc*abd<=0 && cda*cdb<=0) return cout << 1,0;
    return cout << 0,0;
}
