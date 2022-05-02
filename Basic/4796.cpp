// 캠핑 
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
    int t = 1;
    while(1){
        int l,p,v;
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) return 0;

        cout << "Case " << t << ": " << (v/p)*l + min(v%p,l) << '\n';
        t++;
    }
}
