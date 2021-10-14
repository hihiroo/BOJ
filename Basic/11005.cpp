//진법 변환2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    int n, b;
    cin >> n >> b;

    vector<int> ans;

    while(n > 0){
        ans.pb(n%b);
        n = n/b;
    }

    for(int i=ans.size()-1; i>=0; i--)
        ans[i] > 9 ? printf("%c", ans[i]-10+'A') : printf("%d", ans[i]);
}
