//문서 검색
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    string a,b;

    getline(cin,a);
    getline(cin,b);

    int ans = 0;
    for(int i=0; i<a.size(); i++){
        if(a.substr(i,b.size()) == b){
            ans++;
            i += b.size()-1;
        }
    }
    cout << ans;
}
