// 수 묶기
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
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    lli ans = 0;
    for(int i=n-1; i>=0; i--){
        if(v[i] <= 0) break;
        if(i && v[i]*v[i-1] > v[i]){
            ans += (lli)(v[i]*v[i-1]);
            i--;
        }
        else ans += (lli)v[i];
    }
    for(int i=0; i<n; i++){
        if(v[i] >= 0) break;
        if(i+1 < n && v[i]*v[i+1] > v[i]){
            ans += (lli)(v[i]*v[i+1]);
            i++;
        }
        else ans += (lli)v[i];
    }
    cout << ans;
}
