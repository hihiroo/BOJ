#include <bits/stdc++.h>
using namespace std;

bool have(string a, int idx){
    if(idx == a.size()) return true;
    if(a[idx] == '0'){
        if(idx+1 < a.size() && a[idx+1] == '1') return have(a,idx+2);
        return false;
    }
    else if(idx+3 < a.size()){
        if(a[idx+1] != '0' || a[idx+2] != '0') return false;
        for(int i=idx+3; i<a.size(); i++){
            if(a[i] == '1'){
                bool anyok = 0;
                for(int j=i; j<a.size(); j++){
                    if(a[j] == '0') break;
                    anyok |= have(a,j+1);
                }
                return anyok;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        if(have(a,0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
