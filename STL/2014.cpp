//소수의 곱
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli k,n,p[105];
priority_queue<pair<lli,int> > q;

int main(){
    cin>>k>>n;

    for(int i=0; i<k; i++){
        scanf("%lld",&p[i]);
        q.push(mp(-p[i],i));
    }

    lli cnt = 0, max_v = p[k-1];
    while(!q.empty()){
        lli now = -q.top().fst;
        int idx = q.top().snd;
        q.pop();

        if(++cnt == n) return cout<<now,0;

        for(int i=idx; i<k; i++){
            lli next = now*p[i];
            if(q.size() > n && next > max_v) continue;
            if(next < pow(2,31)){
                q.push(mp(-next,i));
                max_v = max(max_v, next);
            }
        }
    }
}
