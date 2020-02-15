//후위 표기식

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    string a, ans="";
    cin>>a;
    stack<char> s;
    for(int i=0; i<a.size(); i++){
        if(a[i] >= 'A' && a[i] <= 'Z') ans += a[i];
        else if(a[i] == '(') s.push('(');
        else if(a[i] == ')'){
            while(s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(a[i] == '+' || a[i] == '-'){
            while(!s.empty() && s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.push(a[i]);
        }
        else{// *,/
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                ans += s.top();
                s.pop();
            }
            s.push(a[i]);
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout<<ans;
}
