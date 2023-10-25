#include <bits/stdc++.h>
using namespace std;

int chk[1000005], ans[1000005];
vector<int> v(100005);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
        chk[v[i]] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=v[i]; j<=1000000; j+=v[i]){
            if(chk[j]){
                ans[v[i]]++;
                ans[j]--;
            }
        }    
    }

    for(int i=0; i<n; i++) cout << ans[v[i]] << ' ';
}