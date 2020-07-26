//책 페이지
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int cnt[10];

void f(string a){
    int k = stoi(a), lv = 1;
    for(int i=1; i<a.size(); i++) lv*=10;

    if(a.size() == 1){
        for(int i=0; i<=k; i++) cnt[i]++;
        return;
    }

    int p = a[0]-'0';
    cnt[p] += k%lv+1;
    f(a.substr(1));

    for(int i=0; i<p; i++){
        cnt[i] += lv;
        for(int j=0; j<10; j++)
            cnt[j] += lv*(a.size()-1)/10;
    }
}

int main(){
    string a;
    cin >> a;

    f(a);
    for(int i=1,lv=1; i<=a.size(); i++,lv*=10)
        cnt[0] -= lv;

    for(int i=0; i<10; i++)
        cout << cnt[i] << " ";
}
