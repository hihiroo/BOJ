//소수&팰린드롬
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

bool chk[10000000];
vector<int> v;


int main(){
    for(int i=2; i<10000000; i++){
        if(chk[i]) continue;
        v.pb(i);
        for(int j=i+i; j<10000000; j+=i) chk[j] = 1;
    }

    int n;
    cin >> n;

    for(int i=0, k; i<v.size(); i++){
        if(v[i] < n) continue;

        string a = "";
        k = v[i];

        while(k > 0){
            a += k%10+'0';
            k /= 10;
        }

        bool isp = 1;
        for(int x=0, y=a.size()-1; x<=y; x++,y--){
            if(a[x] != a[y]){
                isp = 0;
                break;
            }
        }
        if(isp) return cout << v[i],0;
    }
}
