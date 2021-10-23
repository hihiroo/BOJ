// 사탕 게임
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int eat(vector<string> *arr){
    vector<string> v = *arr;
    int n = v.size(), res = 0;

    for(int i=0; i<n; i++){
        int cntR = 1, cntC = 1;
        for(int j=1; j<n; j++){
            if(v[i][j] == v[i][j-1]) cntR++;
            else res = max(res, cntR), cntR = 1;
            if(v[j][i] == v[j-1][i]) cntC++;
            else res = max(res, cntC), cntC = 1;
        }
        res = max(res, max(cntR, cntC));
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j+1<n; j++){
            if(v[i][j] != v[i][j+1]){
                swap(v[i][j], v[i][j+1]);
                ans = max(ans, eat(&v));
                swap(v[i][j], v[i][j+1]);
            }
            if(v[j][i] != v[j+1][i]){
                swap(v[j][i], v[j+1][i]);
                ans = max(ans, eat(&v));
                swap(v[j][i], v[j+1][i]);
            }
        }
    }
    cout << ans;
}
