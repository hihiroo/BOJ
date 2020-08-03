//에너지 모으기
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int ans = 0, n, arr[15];

void f(int cur, int cnt){
    if(cur == (1<<(n-1))-2){
        ans = max(ans,cnt);
        return;
    }

    vector<int> v;
    for(int i=0; i<n; i++){
        if(cur & (1<<i)) continue;
        v.pb(i);
    }

    for(int i=1; i<v.size()-1; i++)
        f(cur|(1<<v[i]), cnt+arr[v[i-1]]*arr[v[i+1]]);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    f(0,0);
    cout << ans;
}
