// 선분 그룹
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

struct Tree{
    vector<int> root, cnt;
    Tree(int n): root(n+1), cnt(n,1){
        for(int i=0; i<n; i++) root[i] = i;
    }

    int find_root(int n){
        if(root[n] == n) return n;
        return root[n] = find_root(root[n]);
    }

    void merge(int a, int b){
        int r1 = find_root(a), r2 = find_root(b);
        cnt[r2] += cnt[r1], cnt[r1] = 0;
        root[r1] = r2;
    }

    bool isconnected(int a, int b){
        return find_root(a) == find_root(b);
    }
};

#define pt pair<int,int>
int ccw(pt a, pt b, pt c){
    lli res = 1LL*(b.fst-a.fst)*(c.snd-b.snd);
    res -= 1LL*(b.snd-a.snd)*(c.fst-b.fst);
    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}

bool cross(pair<pt,pt> line1, pair<pt,pt> line2){
    pt A, B, C, D;
    A = line1.fst, B = line1.snd;
    C = line2.fst, D = line2.snd;

    int abc = ccw(A,B,C), abd = ccw(A,B,D);
    int cda = ccw(C,D,A), cdb = ccw(C,D,B);

    if(abc*abd == 0 && cda*cdb == 0){
        if(A > B) swap(A,B);
        if(C > D) swap(C,D);
        if(A<=D && C<=B) return true;
        return false;
    }
    if(abc*abd<=0 && cda*cdb<=0) return true;
    return false;
}

vector<pair<pt,pt> > v(3000);

int main(){
    cinFast();
    int n;
    cin >> n;

    Tree t(n);

    for(int i=0; i<n; i++){
        pt p1, p2;
        cin >> p1.fst >> p1.snd >> p2.fst >> p2.snd;
        v[i] = {p1,p2};
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(cross(v[i],v[j]) && !t.isconnected(i,j)) t.merge(i,j);
        }
    }

    int ans = 0, gr = 0;
    for(int i=0; i<n; i++){
        if(t.root[i] == i) gr++;
        ans = max(ans,t.cnt[i]);
    }

    cout << gr << '\n' << ans;
}
