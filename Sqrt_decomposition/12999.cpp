//화려한 마을3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n, q, sqrtN, arr[100005];
int cnt[200005], howMany[100005],rootHowMany[350];

vector<int> ans(100005);

struct A{
    int s,e,idx;
}Q[100005];

bool cmp(A a, A b){
    if(a.s/sqrtN == b.s/sqrtN)
        return a.e < b.e;
    return a.s/sqrtN < b.s/sqrtN;
}

void in(int idx){
    int val = arr[idx];
    howMany[cnt[val]]--, rootHowMany[cnt[val]/sqrtN]--;
    howMany[++cnt[val]]++, rootHowMany[cnt[val]/sqrtN]++;
}

void out(int idx){
    int val = arr[idx];
    howMany[cnt[val]]--, rootHowMany[cnt[val]/sqrtN]--;
    howMany[--cnt[val]]++, rootHowMany[cnt[val]/sqrtN]++;
}

void find_ans(int idx){
    for(int i=n/sqrtN; i>=0; i--){
        if(rootHowMany[i]){
            for(int j=min(n,(i+1)*sqrtN-1); j>=0; j--){
                if(howMany[j]){
                    ans[idx] = j;
                    return;
                }
            }
        }
    }
}

int main(){
    cin>>n>>q;
    sqrtN = sqrt(n);

    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        arr[i] += 100000;
    }

    for(int i=0; i<q; i++){
        scanf("%d%d",&Q[i].s,&Q[i].e);
        Q[i].idx = i;
    }
    sort(Q,Q+q,cmp);

    howMany[0] = n, rootHowMany[0] = n;
    int s = Q[0].s, e = Q[0].e;

    for(int i=s; i<=e; i++) in(i);
    find_ans(Q[0].idx);


    for(int i=1; i<q; i++){
        while(Q[i].s < s) in(--s);
        while(Q[i].e > e) in(++e);
        while(Q[i].s > s) out(s++);
        while(Q[i].e < e) out(e--);
        find_ans(Q[i].idx);
    }

    for(int i=0; i<q; i++) printf("%d\n",ans[i]);
}
