//정복자
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

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
    cinFast();

    int n,m,t;
    cin >> n >> m >> t;

    A tree(n+1);
    lli sum = (lli)(t*(n-1)*(n-2)/2);

    priority_queue<pair<int,pair<int,int> > > pq;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push(mp(-c,mp(a,b)));
    }

    while(!pq.empty()){
        int cost = -pq.top().fst;
        int a = pq.top().snd.fst;
        int b = pq.top().snd.snd;
        pq.pop();

        if(tree.connect(a,b)) continue;
        tree.merge(a,b);
        sum += (lli)cost;
    }

    cout << sum;
}
