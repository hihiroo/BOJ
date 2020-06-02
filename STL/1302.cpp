//베스트 셀러
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

map<string,int> m;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        m[a]++;
    }

    string ans;
    int best = 0;

    for(map<string,int>::iterator i = m.begin(); i!=m.end(); i++){
        if(best < i->second){
            ans = i->first;
            best = i->second;
        }
        else if(best == i->second)
            ans = min(ans,i->first);
    }
    cout << ans;
}
