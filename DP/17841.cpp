//UNIST는 무엇의 약자일까?
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

lli dp[100005][6], mod = 1e9+7, n;
vector<string> v(100005);

lli f(int k, int l){
    if(k == n+1 || l == 5){
        if(l == 5) return 1;
        else return 0;
    }
    if(dp[k][l] != -1) return dp[k][l];

    dp[k][l] = f(k+1,l);

    int m = l;
    for(int i=0; i<v[k].size(); i++){
        if(v[k][i] == v[0][m]){
            dp[k][l] += f(k+1,++m);
            dp[k][l] %= mod;
        }
        else break;
        if(m == 5) break;
    }

    return dp[k][l];
}

int main(){
    memset(dp,-1,sizeof(dp));

    cin >> n;

    v[0] = "UNIST";
    for(int i=1; i<=n; i++) cin>>v[i];

    cout << f(1,0);
}
