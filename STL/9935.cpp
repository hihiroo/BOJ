//문자열 폭발
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    string a,bomb;
    cin>>a>>bomb;

    stack<char> s;
    for(int i=0; i<a.size(); i++){
        s.push(a[i]);

        char tmp[50];
        int tmp_size = 0, isSame = 1;

        while(!s.empty() && tmp_size<bomb.size()){
            tmp[tmp_size] = s.top();
            s.pop();
            if(tmp[tmp_size++] != bomb[bomb.size()-tmp_size])
                isSame = 0;
        }

        if(isSame && tmp_size == bomb.size()) continue;
        for(int k=tmp_size-1; k>=0; k--)
            s.push(tmp[k]);
    }

    if(s.empty()) return cout<<"FRULA",0;

    char ans[1000005];
    int ans_idx = s.size();
    ans[ans_idx--] = '\0';

    while(!s.empty()){
        ans[ans_idx--] = s.top();
        s.pop();
    }
    cout<<ans;
}
