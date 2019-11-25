//개똥벌레

#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair

vector<int> bottom, top;

int main(){
    int n,h,l;
    cin>>n>>h;
    
    for(int i=0; i<n; i++){
        cin>>l;
        if(i%2) top.pb(h-l);//종유석
        else bottom.pb(l);//석순
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(),top.end());
    
    int ans = 1000000, cnt_ans = 1;
    for(int i=1; i<=h; i++){//개똥벌레가 날아가는 구간
        int block, idx;
        idx = lower_bound(bottom.begin(),bottom.end(),i)-bottom.begin();
        block = bottom.size() - idx;
        idx = lower_bound(top.begin(),top.end(),i) - top.begin();
        block += idx;
        
        if (block > ans) continue;
        if(block == ans) cnt_ans++;
        else{
            cnt_ans = 1;
            ans = block;
        }
    }
    cout<<ans<<" "<<cnt_ans;
}