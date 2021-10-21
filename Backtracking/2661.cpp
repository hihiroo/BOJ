//좋은 수열
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int n, finish;

void f(int idx, string a){
    if(finish) return;
    if(idx == n){
        finish = 1;
        cout << a;
        return;
    }

    for(char last='1'; last<='3'; last++){
        a += last;

        int cant = 0, l = a.size();
        for(int i=1; i*2<=l; i++){
            if(a.substr(l-i) == a.substr(l-2*i,i)){
                cant = 1;
                break;
            }
        }

        if(!cant) f(idx+1,a);
        a.pop_back();
    }
}

int main(){
    cin >> n;

    f(0,"");
}
