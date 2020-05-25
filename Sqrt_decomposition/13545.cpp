//수열과 쿼리0
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair
#define pii pair<int,int>

int arr[100005], ans[100005], sqrtN, n;
vector<deque<int> > dq(200005);
int cnt[100005], sqrtCnt[500];

struct Q{
    int s, f, idx;
}q[100005];

bool cmp(Q a, Q b){
    if(a.s/sqrtN == b.s/sqrtN)
        return a.f < b.f;
    return a.s/sqrtN < b.s/sqrtN;
}

int len(int val){
    if(dq[val].empty()) return 0;
    return dq[val].back()-dq[val].front();
}

void in(int i){
    int val = arr[i];

    cnt[len(val)]--;
    sqrtCnt[len(val)/sqrtN]--;

    if(dq[val].empty() || dq[val].back()<i) dq[val].pb(i);
    else dq[val].push_front(i);

    cnt[len(val)]++;
    sqrtCnt[len(val)/sqrtN]++;
}

void out(int i){
    int val = arr[i];

    cnt[len(val)]--;
    sqrtCnt[len(val)/sqrtN]--;

    if(dq[val].back() == i) dq[val].pop_back();
    else dq[val].pop_front();

    cnt[len(val)]++;
    sqrtCnt[len(val)/sqrtN]++;
}

void find_ans(int idx){
    for(int i=n/sqrtN; i>=0; i--){
        if(!sqrtCnt[i]) continue;
        for(int j=min(n,(i+1)*sqrtN-1); j>=0; j--){
            if(cnt[j]){
                ans[idx] = j;
                return;
            }
        }
    }
}

int main(){
    cin >> n;

    sqrtN = sqrt(n);

    arr[0] = 100000;
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        arr[i] += arr[i-1];
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        scanf("%d%d",&q[i].s,&q[i].f);
        q[i].s--;
        q[i].idx = i;
    }
    sort(q,q+m,cmp);

    cnt[0] = n, sqrtCnt[0] = n;

    int s = q[0].s, f = q[0].f;

    for(int i=s; i<=f; i++) in(i);
    find_ans(q[0].idx);

    for(int i=1; i<m; i++){
        while(s > q[i].s) in(--s);
        while(f < q[i].f) in(++f);
        while(s < q[i].s) out(s++);
        while(f > q[i].f) out(f--);
        find_ans(q[i].idx);
    }

    for(int i=0; i<m; i++) printf("%d\n",ans[i]);
}
