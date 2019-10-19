//poklon

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

int rootN,arr[500005],cnt[500005];
int twice_cnt;

struct A{
    int s,f,idx;
}Q[500005];

bool cmp(A a, A b){
    if(a.s/rootN == b.s/rootN)
        return a.f < b.f;
    return a.s/rootN < b.s/rootN;
}

void in(int num){
    if(cnt[num] == 2) twice_cnt--;
    if(++cnt[num] == 2) twice_cnt++;
}

void out(int num){
    if(cnt[num] == 2) twice_cnt--;
    if(--cnt[num] == 2) twice_cnt++;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    rootN = sqrt(n);

    map<int,int> appear;
    int appear_num = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        if(appear.find(arr[i]) == appear.end())
            appear[arr[i]] = ++appear_num;
        arr[i] = appear[arr[i]];
    }

    for(int i=0; i<q; i++){
        scanf("%d%d",&Q[i].s,&Q[i].f);
        Q[i].idx = i;
    }
    sort(Q,Q+q,cmp);

    vector<int> ans(500005);
    int x = Q[0].s, y = Q[0].f;

    for(int i=x; i<=y; i++) in(arr[i]);
    ans[Q[0].idx] = twice_cnt;

    for(int i=1; i<q; i++){
        while(Q[i].s < x)in(arr[--x]);
        while(Q[i].f > y)in(arr[++y]);
        while(Q[i].s > x)out(arr[x++]);
        while(Q[i].f < y)out(arr[y--]);

        ans[Q[i].idx] = twice_cnt;
    }


    for(int i=0; i<q; i++)
        printf("%d\n",ans[i]);
}
