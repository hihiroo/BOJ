//수열과 쿼리22

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

lli size, arr[400005];

void construct(){
    for(lli i=size; i>0; i--)
        arr[i] = arr[i*2] + arr[i*2+1];
}

void update(lli i, lli val){
    i += size;
    arr[i] = val;
    while(i > 1){
        i/=2;
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}

lli sum(lli L, lli R, lli vtx, lli nL, lli nR){
    if(R < nL || L > nR) return 0;
    if(L <= nL && nR <= R) return arr[vtx];
    lli mid = (nL + nR)/2;
    return sum(L,R,vtx*2,nL,mid)+sum(L,R,vtx*2+1,mid+1,nR);
}

int main(){
    lli n, lv = 1;
    scanf("%lld",&n);
    while(lv < n){
        size += lv;
        lv *= 2;
    }

    for(lli i=1; i<=n; i++)
        scanf("%lld",&arr[size+i]);
    construct();

    lli m,q,a,b,c,num=0;
    scanf("%lld",&m);

    priority_queue<pair<lli,pair<lli,pair<lli,lli> > > > q2;
    queue<pair<lli,lli> > q1;

    for(lli i=0; i<m; i++){
        scanf("%lld%lld%lld",&q,&a,&b);
        if(q == 1) q1.push(mp(a,b));
        else{
            scanf("%lld",&c);
            q2.push(mp(-a,mp(b,mp(c,num++))));
        }
    }

    lli cnt = 0;
    vector<lli> ans(100005);

    while(!q2.empty() && -q2.top().fst == cnt){
        lli l = q2.top().snd.fst;
        lli r = q2.top().snd.snd.fst;
        lli q_num = q2.top().snd.snd.snd;
        q2.pop();

        ans[q_num] = sum(l,r,1,1,size+1);
    }

    while(!q1.empty()){
        lli idx = q1.front().fst;
        lli val = q1.front().snd;
        q1.pop();
        update(idx,val), cnt++;

        while(!q2.empty() && -q2.top().fst == cnt){
            lli l = q2.top().snd.fst;
            lli r = q2.top().snd.snd.fst;
            lli q_num = q2.top().snd.snd.snd;
            q2.pop();

            ans[q_num] = sum(l,r,1,1,size+1);
        }
    }

    for(lli i=0; i<num; i++)
        printf("%lld\n",ans[i]);
}
