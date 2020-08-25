//수열과 쿼리8
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli tree[100005], sqrtN, arr[100005];

struct Q{
    int idx, s, f;
}q[100005];

void update(int i, int val){
    while(i <= 100000){
        tree[i] += val;
        i += (i & -i);
    }
}

lli sum(int i){
    i = min(100000,i);
    
    lli ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

bool cmp(Q a, Q b){
    if(a.s/sqrtN != b.s/sqrtN)
        return a.s/sqrtN < b.s/sqrtN;
    return a.f < b.f;
}

int main(){
    cinFast();
    int n, k, m;
    cin >> n >> k;

    sqrtN = sqrt(n);

    for(int i=1; i<=n; i++) cin >> arr[i];

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> q[i].s >> q[i].f;
        q[i].idx = i;
    }
    sort(q,q+m,cmp);

    vector<lli> ans(m);

    int s = q[0].s, f = q[0].f;
    lli cnt = 0;

    for(int i=s; i<=f; i++){
        cnt += sum(arr[i]+k) - sum(arr[i]-k-1);
        update(arr[i],1);
    }
    ans[q[0].idx] = cnt;

    for(int i=1; i<m; i++){
        while(q[i].s < s){
            cnt += sum(arr[--s]+k) - sum(arr[s]-k-1);
            update(arr[s],1);
        }
        while(q[i].f > f){
            cnt += sum(arr[++f]+k) - sum(arr[f]-k-1);
            update(arr[f],1);
        }
        while(q[i].s > s){
            update(arr[s],-1);
            cnt -= sum(arr[s]+k) - sum(arr[s++]-k-1);
        }
        while(q[i].f < f){
            update(arr[f],-1);
            cnt -= sum(arr[f]+k) - sum(arr[f--]-k-1);
        }
        ans[q[i].idx] = cnt;
    }

    for(int i=0; i<m; i++) cout << ans[i] << '\n';
}
