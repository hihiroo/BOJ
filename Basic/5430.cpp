//AC
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    int t,n,a;
    cin>>t;
    for(; t>0; t--){
        string order;
        cin>>order>>n;

        deque<int> s;
        char foo;
        cin>>foo;
        if(n){
            cin>>a;
            s.pb(a);
        }
        for(int i=1; i<n; i++){
            cin>>foo>>a;
            s.pb(a);
        }
        cin>>foo;

        bool Isfront = true, poss = true;
        for(int i=0; i<order.size(); i++){
            if(order[i] == 'R') Isfront ^= 1;
            else{
                if(s.empty()){
                    poss = false;
                    break;
                }
                else if(Isfront) s.pop_front();
                else s.pop_back();
            }
        }
        if(!poss) cout<<"error\n";
        else{
            cout<<"[";
            if(Isfront){
                while(!s.empty()){
                    cout<<s.front();
                    s.pop_front();
                    if(!s.empty()) cout<<",";
                }
            }
            else{
                while(!s.empty()){
                    cout<<s.back();
                    s.pop_back();
                    if(!s.empty()) cout<<",";
                }
            }
            cout<<"]\n";
        }
    }
}
