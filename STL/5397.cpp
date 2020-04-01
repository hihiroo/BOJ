//키로거
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        stack<char> left,right;
        string a;
        cin>>a;

        for(int i=0; i<a.size(); i++){
            if(a[i] == '<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            }
            else if(a[i] == '>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
            }
            else if(a[i] == '-'){
                if(!left.empty()) left.pop();
            }
            else left.push(a[i]);
        }

        string x = "", y = "";
        while(!left.empty()){
            x += left.top();
            left.pop();
        }
        reverse(x.begin(),x.end());
        while(!right.empty()){
            y += right.top();
            right.pop();
        }


        cout << x+y << '\n';
    }
}
