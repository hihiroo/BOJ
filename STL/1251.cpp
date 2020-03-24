//단어 나누기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<string> ans;
int main(){
    string a;
    cin>>a;
    
    for(int i=0; i<a.size()-2; i++){//0~i, i+1~j
        string x = a.substr(0,i+1);
        reverse(x.begin(),x.end());
        for(int j=i+1; j<a.size()-1; j++){
            string y = a.substr(i+1,j-i);
            reverse(y.begin(),y.end());
            
            string z = a.substr(j+1);
            reverse(z.begin(),z.end());
            
            ans.pb(x+y+z);
        }
    }
    
    sort(ans.begin(),ans.end());
    cout<<ans[0];
}
