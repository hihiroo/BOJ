// 수 이어쓰기 2
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0, lv = 1, lvpow = 10;
    for(int i=1; i<=n; i++){
        if(i == lvpow) lv++, lvpow *= 10;
        cnt += lv;

        while(cnt > k){
            cnt--;
            i /= 10;
        }
        if(cnt == k) return cout << i%10,0;
    }
    cout << -1;
}
