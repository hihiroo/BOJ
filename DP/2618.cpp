//경찰차
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<pair<int,int> > v(1005);
int dp[1005][1005], n, m, nMove[1005][1005];

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.fst-b.fst) + abs(a.snd-b.snd);
}

int f(int a, int b){
    if(max(a,b) == m+1) return 0;
    if(dp[a][b] != -1) return dp[a][b];

    int next = max(a,b)+1;

    dp[a][b] = f(a,next)+dist(v[b],v[next]);
    nMove[a][b] = 2;

    int k = f(next,b)+dist(v[next],v[a]);
    if(k < dp[a][b]){
        nMove[a][b] = 1;
        dp[a][b] = k;
    }
    return dp[a][b];
}

int main(){
    cinFast();
    memset(dp,-1,sizeof(dp));
    cin >> n;

    v[0] = mp(1,1);
    v[1] = mp(n,n);

    cin >> m;
    for(int i=2; i<=m+1; i++)
        cin >> v[i].fst >> v[i].snd;

    cout << f(0,1) << '\n';

    int a = 0, b = 1;
    for(int i=0; i<m; i++){
        cout << nMove[a][b] << '\n';
        if(nMove[a][b] == 1) a = max(a,b)+1;
        else b = max(a,b)+1;
    }
}
