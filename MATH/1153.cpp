//네 개의 소수
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int chk[1000005];
vector<int> v;
vector<vector<int> > ans(1000001);

int main(){
    for(int i=2; i<=1000000; i++){
        if(chk[i]) continue;
        v.pb(i);
        for(int j=2; i*j<=1000000; j++) chk[i*j] = 1;
    }

    for(int i=0; i<168; i++)
        for(int j=i; j<168; j++)
            for(int k=j; k<168; k++)
                ans[v[i]+v[j]+v[k]].pb(v[i]),ans[v[i]+v[j]+v[k]].pb(v[j]),ans[v[i]+v[j]+v[k]].pb(v[k]);

    int n;
    cin >> n;

    for(int i=0; v[i]<n; i++){
        if(ans[n-v[i]].size()){
            cout << v[i] << " " << ans[n-v[i]][0] << " " << ans[n-v[i]][1] << " " << ans[n-v[i]][2];
            return 0;
        }
    }
    cout << -1;
}
