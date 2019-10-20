//8462 배열의 힘

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

int arr[100005],rootN;
int cnt[1000005];

struct A{
    int s, f, idx;
}Q[100005];

bool cmp(A a, A b){
    if(a.s/rootN == b.s/rootN) return a.f < b.f;
    return a.s/rootN < b.s/rootN;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rootN = sqrt(n);

    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);

    for(int i=0; i<m; i++){
        scanf("%d%d",&Q[i].s, &Q[i].f);
        Q[i].idx = i;
    }
    sort(Q,Q+m,cmp);


    vector<lli> ans(100005);
    int x = Q[0].s, y = Q[0].f;
    lli power = 0;

    for(int i=x; i<=y; i++){
        power += (lli)(2*cnt[arr[i]]+1)*(lli)arr[i];
        cnt[arr[i]]++;
    }
    ans[Q[0].idx] = power;

    for(int i=1; i<m; i++){
        while(Q[i].s < x){
            power += (lli)(2*cnt[arr[--x]]+1)*(lli)arr[x];
            cnt[arr[x]]++;
        }
        while(Q[i].f > y){
            power += (lli)(2*cnt[arr[++y]]+1)*(lli)arr[y];
            cnt[arr[y]]++;
        }
        while(Q[i].s > x){
            power += (lli)(-2*cnt[arr[x]]+1)*(lli)arr[x];
            cnt[arr[x++]]--;
        }
        while(Q[i].f < y){
            power += (lli)(-2*cnt[arr[y]]+1)*(lli)arr[y];
            cnt[arr[y--]]--;
        }
        ans[Q[i].idx] = power;
    }
    for(int i=0; i<m; i++)
        printf("%lld\n",ans[i]);
}
