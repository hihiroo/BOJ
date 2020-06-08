//스티커 수집
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

#define it map<int,int>::iterator

int n, price[35], value[35],k;
map<int,int> r,l;

void f(int idx, int p, int val, bool isLeft){
    if(isLeft && idx == (n+1)/2){
        if(l.count(-val) && l[-val]<p);
        else l[-val] = p;
        return;
    }
    if(!isLeft && idx == n){
        if(r.count(-val) && r[-val]<p);
        else r[-val] = p;
        return;
    }
    f(idx+1,p,val,isLeft);
    f(idx+1,p+price[idx],val+value[idx],isLeft);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> value[i];
    cin >> k;

    int sum = 0, cnt, a;
    cin >> cnt;
    while(cnt--){
        cin >> a;
        sum += price[a];
    }

    f(0,0,0,1);
    f((n+1)/2,0,0,0);

    vector<int> lkey, rkey;

    int min_v = 1e9;
    for(it i=l.begin(); i!=l.end(); i++){
        min_v = min(min_v, i->snd);
        i->snd = min_v;
        lkey.pb(-(i->fst));
    }

    min_v = 1e9;
    for(it i=r.begin(); i!=r.end(); i++){
        min_v = min(min_v, i->snd);
        i->snd = min_v;
        rkey.pb(-(i->fst));
    }

    sort(lkey.begin(), lkey.end());
    sort(rkey.begin(),rkey.end());

    int ans = 1e9;
    for(int i=0; i<lkey.size(); i++){
        int lval = lkey[i];
        int idx = lower_bound(rkey.begin(), rkey.end(),
                    max(0,k-lval))-rkey.begin();

        if(idx == rkey.size()) continue;
        ans = min(ans,r[-rkey[idx]] + l[-lval]);
    }
    for(int i=0; i<rkey.size(); i++){
        int rval = rkey[i];
        int idx = lower_bound(lkey.begin(), lkey.end(),
                    max(0,k-rval))-lkey.begin();

        if(idx == lkey.size()) continue;
        ans = min(ans,r[-rval]+l[-lkey[idx]]);
    }

    if(ans == 1e9) return cout << -1,0;
    cout << max(0,ans-sum);
}
