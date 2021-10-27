// 연속구간
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    string a[3];
    cin >> a[0] >> a[1] >> a[2];

    for(int i=0; i<3; i++){
        int cnt = 1, ans = 1;
        for(int j=1; j<8; j++){
            if(a[i][j] == a[i][j-1]) ans = max(ans, ++cnt);
            else cnt = 1;
        }
        cout << ans << '\n';
    }
}
