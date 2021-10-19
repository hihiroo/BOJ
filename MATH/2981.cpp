// 검문
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cinFast();
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> sub(n*n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sub[i*n+j] = abs(v[i]-v[j]);

    int k = sub[0];
    for(int i=1; i<n*n; i++) k = gcd(k,sub[i]);

    vector<int> ans;
    for(int i=2; i*i<=k; i++){
        if(k % i != 0) continue;
        ans.pb(i);
        if(i*i != k) ans.pb(k/i);
    }
    ans.pb(k);

    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}
