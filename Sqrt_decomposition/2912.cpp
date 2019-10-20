//백설공주와 난쟁이

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


int arr[300005],n,rootN,c,cnt[10005];

struct A{
    int s, f, idx;
}Q[10005];


bool cmp(A a, A b){
    if(a.s/rootN == b.s/rootN) return a.f < b.f;
    else return a.s/rootN < b.s/rootN;
}

int main(){
    scanf("%d%d",&n,&c);
    rootN = sqrt(n);

    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    vector<int> ans(10005);
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%d%d",&Q[i].s, &Q[i].f);
        Q[i].idx = i;
        Q[i].s--, Q[i].f--;
    }
    sort(Q,Q+m,cmp);

    int x = Q[0].s, y = Q[0].f, most_color = 0;
    for(int i=x; i<=y; i++) cnt[arr[i]]++;
    for(int i=1; i<=10000; i++)
        if(cnt[most_color] < cnt[i]) most_color = i;
    if(cnt[most_color] > (y-x+1)/2)
        ans[Q[0].idx] = most_color;

    for(int i=1; i<m; i++){
        while(Q[i].s < x) cnt[arr[--x]]++;
        while(Q[i].f > y) cnt[arr[++y]]++;
        while(Q[i].s > x) cnt[arr[x++]]--;
        while(Q[i].f < y) cnt[arr[y--]]--;

        most_color = 0;
        for(int j=1; j<=10000; j++)
            if(cnt[most_color] < cnt[j]) most_color = j;
        if(cnt[most_color] > (Q[i].f-Q[i].s+1)/2)
            ans[Q[i].idx] = most_color;
    }

    for(int i=0; i<m; i++){
        if(ans[i]) printf("yes %d\n",ans[i]);
        else printf("no\n");
    }
}
