// 크게 만들기
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
    int n, k;
    cin >> n >> k;

    string a;
    cin >> a;

    string s;
    for(int i=0; i<n; i++){
        while(k && s.size() && s.back() < a[i]){
            s.pop_back();
            k--;
        }
        s += a[i];
    }

    for(int i=0; i<s.size()-k; i++) cout << s[i];
}
