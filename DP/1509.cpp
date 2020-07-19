//팰린드롬 분할
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string a;
int p[2505][2505], dp[2505];

int isP(int s, int e){
    if(s == e) return 1;
    if(p[s][e] != -1) return p[s][e];

    if((s+1 == e || isP(s+1,e-1)) && a[s] == a[e])
        p[s][e] = 1;
    else p[s][e] = 0;

    return p[s][e];
}

int solve(int n){
    if(n < 0) return 0;
    if(dp[n]) return dp[n];

    dp[n] = n+1;
    for(int i=0; i<=n; i++)
        if(isP(i,n)) dp[n] = min(dp[n], solve(i-1)+1);

    return dp[n];
}

int main(){
    memset(p,-1,sizeof(p));

    cin >> a;
    cout << solve(a.size()-1);
}
