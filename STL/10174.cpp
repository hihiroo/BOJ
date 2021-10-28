//팰린드롬
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string a;
        getline(cin, a, '\n');

        bool isF = 1;
        for(int j=0; j<a.size()-j-1; j++){
            if(tolower(a[j]) != tolower(a[a.size()-j-1])){
                isF = 0;
                break;
            }
        }
        if(isF) cout << "Yes\n";
        else cout << "No\n";
    }
}
