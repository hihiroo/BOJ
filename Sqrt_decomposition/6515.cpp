//Frequent values

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

int cnt[200005],rootN,arr[100005];
int cnt_arr[100005], sqrt_cnt_arr[400], rootCnt;
struct A{
    int s, f, idx;
}Q[100005];

bool cmp(A a, A b){
    if(a.s/rootN == b.s/rootN) return a.f < b.f;
    return a.s/rootN < b.s/rootN;
}

void in(int val){
    if(cnt_arr[cnt[val]] != 0){
        cnt_arr[cnt[val]]--;
        sqrt_cnt_arr[cnt[val]/rootCnt]--;
    }
    cnt[val]++;
    cnt_arr[cnt[val]]++;
    sqrt_cnt_arr[cnt[val]/rootCnt]++;
}

void out(int val){
    cnt_arr[cnt[val]]--;
    sqrt_cnt_arr[cnt[val]/rootCnt]--;
    cnt[val]--;
    cnt_arr[cnt[val]]++;
    sqrt_cnt_arr[cnt[val]/rootCnt]++;
}

int main(){
    int n,q;
    vector<int> ans(100005);

    while(1){
        scanf("%d",&n);
        if(n == 0) return 0;
        rootN = sqrt(n);
        rootCnt = sqrt(100000);
        scanf("%d",&q);

        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);

        for(int i=0; i<q; i++){
            scanf("%d%d",&Q[i].s,&Q[i].f);
            Q[i].idx = i;
        }
        sort(Q,Q+q,cmp);

        memset(cnt,0,sizeof(cnt));
        memset(cnt_arr,0,sizeof(cnt_arr));
        memset(sqrt_cnt_arr,0,sizeof(sqrt_cnt_arr));

        int x = Q[0].s, y = Q[0].f, most = 0;

        for(int i=x; i<=y; i++){
            in(arr[i]+100000);
            most = max(most,cnt[arr[i]+100000]);
        }
        ans[Q[0].idx] = most;

        for(int i=1; i<q; i++){
            while(Q[i].s < x) in(arr[--x]+100000);
            while(Q[i].f > y) in(arr[++y]+100000);
            while(Q[i].s > x) out(arr[x++]+100000);
            while(Q[i].f < y) out(arr[y--]+100000);

            for(int j=100000/rootCnt; j>=0; j--){
                if(sqrt_cnt_arr[j]){
                    for(int k=min(100000,rootCnt*(j+1)-1); k>=0; k--){
                        if(cnt_arr[k]){
                            ans[Q[i].idx] = k;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        for(int i=0; i<q; i++)
            printf("%d\n",ans[i]);
    }
}
