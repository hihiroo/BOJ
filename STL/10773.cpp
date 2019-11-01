// 제로

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int main(){
    int n,a;
    stack<int> s;
    cin>>n;
    for(; n>0; n--){
        cin>>a;
        if(a == 0 && !s.empty()) s.pop();
        else s.push(a);
    }
    lli cnt = 0;
    while(!s.empty()){
        cnt += s.top();
        s.pop();
    }
    printf("%lld",cnt);
}


