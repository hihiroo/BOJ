// -2진수
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    int n;
    cin >> n;

    vector<bool> v;
    if(n == 0) v.pb(0);
    while(n){
        if(n%-2 == -1){
            v.pb(1);
            n--;
        }
        else v.pb(n%-2);
        n = n/-2;
    }

    for(int i=v.size()-1; i>=0; i--)
        cout << v[i];
}
