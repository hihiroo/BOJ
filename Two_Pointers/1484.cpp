//다이어트
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){
    lli g;
    cin >> g;

    lli s = 1, e = 1;

    vector<lli> ans;

    while(1){
        lli k = e*e-s*s;
        if(k == g) ans.pb(e);
        if(k > g) s++;
        else if(e == 100000) break;
        else e++;
    }

    if(ans.size() == 0) cout << -1;
    
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}
