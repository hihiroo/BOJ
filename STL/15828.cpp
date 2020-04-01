//Router
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;


int main(){
    int n;
    cin>>n;

    queue<int> q;
    while(1){
        int a;
        cin >> a;
        if(a == -1) break;

        if(a == 0 && !q.empty()) q.pop();
        else{
            if(q.size()+1 <= n) q.push(a);
        }
    }

    if(q.empty()) return cout << "empty",0;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
