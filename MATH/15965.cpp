//K번째 소수 
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool chk[9000005] = {1,1};
vector<int> p;

int main(){
    for(int i=2; i<=3000; i++){
        if(chk[i]) continue;
        for(int j=2; i*j<=9000000; j++)
            chk[i*j] = 1;
    }

    for(int i=2; i<=9000000; i++)
        if(!chk[i]) p.pb(i);

    int k;
    cin >> k;

    cout << p[k-1];
}
