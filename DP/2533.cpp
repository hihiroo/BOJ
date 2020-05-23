//사회망 서비스(SNS)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair

vector<vector<int> > v(1000005);
int dp[1000005][2], par[1000005];

int f(int vtx, int early){
    if(dp[vtx][early] != -1) return dp[vtx][early];

    dp[vtx][early] = early;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(next == par[vtx]) continue;
        par[next] = vtx;

        if(early) dp[vtx][early] += min(f(next,0),f(next,1));
        else dp[vtx][early] += f(next,1);
    }
    return dp[vtx][early];
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].pb(b), v[b].pb(a);
    }

    memset(dp,-1,sizeof(dp));
    cout << min(f(1,0),f(1,1));
}
