// 수리공 항승
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
    cinFast();
    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 0, start = -10000;
    for(int i=0; i<n; i++){
        if(v[i]-start >= l){
            ans++;
            start = v[i];
        }
    }
    cout << ans;
}
