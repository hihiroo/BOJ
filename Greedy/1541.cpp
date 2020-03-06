//잃어버린 괄호
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    string a;
    cin>>a;

    stack<int> s;
    int ans = 0, minu = 0, cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != '-' && a[i] != '+'){
            s.push(a[i]-'0');
            continue;
        }
        int lv = 1, sum = 0;
        while(!s.empty()){
            sum += lv*s.top();
            s.pop();
            lv*=10;
        }

        if(minu) cnt += sum;
        else ans += sum;

        if(a[i] == '-') minu = 1;
    }

    int lv = 1, sum = 0;
    while(!s.empty()){
        sum += lv*s.top();
        s.pop();
        lv*=10;
    }
    if(minu) cnt += sum;
    else ans += sum;

    ans -= cnt;
    cout<<ans;
}
