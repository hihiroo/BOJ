//회사에 있는 사람
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

map<string,bool> m;

int main(){
    cinFast();

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string name, a;
        cin >> name >> a;
        if(a == "enter") m[name] = 1;
        else m[name] = 0;
    }

    for(auto it = m.rbegin(); it != m.rend(); it++){
        if(it->snd == 1) cout << it->fst << '\n';
    }
}
