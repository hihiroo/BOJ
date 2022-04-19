// 문자열
#include <bits/stdc++.h>
using namespace std;
#define lli unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

vector<char> ans;
int n, cnt[30], finish;

void f(int idx, int s, int e, int remain){
    if(remain > (n-idx+1)) return;
    if(idx == n+1){
        if(remain) return;
        finish = 1;
        return;
    }
    while(s < e && !cnt[s]) s++;
    if(cnt[s]){
        cnt[s]--;
        f(idx+1,s,e,remain-1);
        cnt[s]++;
        if(finish){
            ans.pb(s+'A');
            return;
        }
    }
    cnt[e+1] = idx-1;
    f(idx+1,s,e+1,remain+idx-1);
    cnt[e+1] = 0;
    if(finish){
        ans.pb(e+1+'A');
        return;
    }
}

int main(){
    cinFast();
    cin >> n;
    f(1, 0, -1, 0);
    if(!finish) return cout << -1,0;
    for(int i=n-1; i>=0; i--) cout << ans[i];
}
