// 수열의 합
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;


int main(){
    lli n,l;
    cin >> n >> l;

    for(int i=l; i<=100; i++){
        lli low = 0, high = 1e9, last;
        while(low+1 < high){
            lli mid = (low + high)/2;
            lli b = mid, a = mid-i+1;
            if(b*(b+1)/2-(a-1)*a/2 >= n)
                high = mid;
            else low = mid;
        }
        lli b = high, a = high-i+1;
        if(a < 0) continue;
        if(b*(b+1)/2 - (a-1)*a/2 == n){
            for(int j=a; j<=b; j++)
                cout << j << " ";
            return 0;
        }
    }

    cout << -1;
}
