//우주신과의 교감
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

pair<double,double> coordi[1005];

double dist(double a, double b, double x, double y){
    return sqrt((a-x)*(a-x) + (b-y)*(b-y));
}

struct A{
    vector<int> root;
    A(int n): root(n+1){
        for(int i=1; i<=n; i++)
            root[i] = i;
    }

    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }

    void merge(int a, int b){
        int r1 = find(a);
        root[r1] = find(b);
    }

    bool connect(int a, int b){
        return find(a) == find(b);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    A god(n);

    for(int i=1; i<=n; i++)
        cin >> coordi[i].fst >> coordi[i].snd;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(god.connect(a,b)) continue;
        god.merge(a,b);
    }

    priority_queue<pair<double,pair<int,int> > > pq;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(god.connect(i,j)) continue;

            int a = coordi[i].fst, b = coordi[i].snd;
            int x = coordi[j].fst, y = coordi[j].snd;
            pq.push(mp(-dist(a,b,x,y),mp(i,j)));
        }
    }

    double ans = 0;
    while(!pq.empty()){
        double cost = -pq.top().fst;
        int x = pq.top().snd.fst;
        int y = pq.top().snd.snd;
        pq.pop();

        if(god.connect(x,y)) continue;
        god.merge(x,y);
        ans += cost;
    }

    printf("%.2f",ans);
}
