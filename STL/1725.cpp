#include <bits/stdc++.h>
using namespace std;

#define lli long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    stack<pair<lli,int> > s;
    lli ans = 0;
    for(int i=0; i<n; i++){
        lli a;
        cin >> a;
        
        while(!s.empty() && s.top().first > a){
            lli h = s.top().first, w = 0;
            s.pop();
            if(!s.empty()) w = s.top().second+1;
            ans = max(ans, (lli)(i-w)*h);
        }
        s.push({a,i});
    }
    int i = n;
    while(!s.empty()){
        lli h = s.top().first, w = 0;
        s.pop();
        if(!s.empty()) w = s.top().second+1;
        ans = max(ans, (lli)(i-w)*h);
    }

    cout << ans << '\n';
}