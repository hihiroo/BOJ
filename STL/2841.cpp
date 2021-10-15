//외계인의 기타 연주
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    cinFast();
    int n, p;

    cin >> n >> p;
    vector<vector<int> > v(7);

    int ans = 0;
    for(int i=0; i<n; i++){
        int c, k;
        cin >> c >> k;

        while(v[c].size() && v[c].back() > k){
            ans++;
            v[c].pop_back();
        }
        if(!v[c].size() || v[c].back() != k){
            ans++;
            v[c].pb(k);
        }
    }
    cout << ans;
}
