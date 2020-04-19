//가르침
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<string> v(51);
int visit[30], n, k, ans;

void solve(int cnt, int idx){
    if(cnt == k-5){
        int yes = 0;
        for(int i=0; i<n; i++){
            bool poss = 1;
            for(int j=0; j<v[i].size(); j++)
                if(!visit[v[i][j]-'a']) poss = 0;
            if(poss) yes++;
        }
        ans = max(ans,yes);
        return;
    }
    if(idx >= 26) return;

    solve(cnt,idx+1);
    if(visit[idx] == 2) return;

    if(!visit[idx]){
        visit[idx] = 1;
        solve(cnt+1,idx+1);
        visit[idx] = 0;
    }
}


int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> v[i];

    if(k < 5) return cout << 0,0;

    string pass = "antic";
    for(int i=0; i<pass.size(); i++)
        visit[pass[i]-'a'] = 2;

    solve(0,0);
    cout << ans;
}
