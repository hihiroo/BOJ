// 뒤집기
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
    string a;
    cin >> a;

    int cnt1 = (a[0] == '1'), cnt0 = (a[0] == '0');
    for(int i=1; i<a.size(); i++){
        if(a[i] != a[i-1]){
            if(a[i] == '1') cnt1++;
            else cnt0++;
        }
    }
    cout << min(cnt0,cnt1);
}
