//연돌이와 고잠녀
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
using namespace std;

struct P{
    double x, y;
};

struct L{
    P a, b;
    double lean, y_;

    void init(){
        lean = (a.y-b.y)/(a.x-b.x);
        y_ = a.y - a.x*lean; // y절편
    }
};

vector<L> s(2005), an(2005);

double ppdist(P a, P b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double pl(L l, P a){
    double x = a.x, y = a.y, k = l.lean, y_ = l.y_;
    double mx = min(l.a.x,l.b.x), Mx = max(l.a.x,l.b.x);

    double p = (x-k*y_+k*y)/(1+k*k);
    if(mx <= p && p <= Mx) return abs(k*x-y+y_)/sqrt(k*k+1);
    else return 100000*sqrt(2);
}

double dist(L p, L q){
    double pp = min(ppdist(p.a,q.a),
                    min(ppdist(p.a,q.b),
                        min(ppdist(p.b,q.a),
                            ppdist(p.b,q.b))));

    return min(pp, min(pl(p,q.a),
                        min(pl(p,q.b),
                            min(pl(q,p.a),
                                pl(q,p.b)))));
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        scanf("%lf%lf%lf%lf",&s[i].a.x,&s[i].a.y,&s[i].b.x,&s[i].b.y);
        s[i].init();
    }

    for(int i=0; i<m; i++){
        scanf("%lf%lf%lf%lf",&an[i].a.x,&an[i].a.y,&an[i].b.x,&an[i].b.y);
        an[i].init();
    }

    double ans = 100000*sqrt(2);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = min(ans,dist(s[i],an[j]));
        }
    }

    printf("%.6f\n",ans);
}
