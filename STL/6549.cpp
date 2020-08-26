//히스토그램에서 가장 큰 직사각형
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    cinFast();
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;

        stack<pair<lli,lli> > s;

        lli ans = 0, a;
        for(int i=0; i<n; i++){
            cin >> a;

            lli idx = i;
            while(!s.empty() && s.top().fst > a){
                lli val = s.top().fst;
                idx = min(idx,s.top().snd);

                ans = max(ans,val*(i-s.top().snd));
                s.pop();
            }
            s.push(mp(a,idx));
        }
        while(!s.empty()){
            ans = max(ans,s.top().fst*(n-s.top().snd));
            s.pop();
        }
        cout << ans << '\n';
    }
}
