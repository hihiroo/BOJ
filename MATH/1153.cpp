//네 개의 소수
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int chk[1000005];
vector<int> v;

int main(){
    for(int i=2; i<=1000000; i++){
        if(chk[i]) continue;
        v.pb(i);
        for(int j=2; i*j<=1000000; j++) chk[i*j] = 1;
    }

    int n;
    cin >> n;

    if(n < 8) return cout << -1,0;
    if(n%2){
        cout << "2 3 ";
        n -= 5;
    }
    else{
        cout << "2 2 ";
        n -= 4;
    }

    for(int i=0; i<v.size(); i++){
        if(chk[n-v[i]]) continue;
        return cout << v[i] << " " << n-v[i],0;
    }
}
