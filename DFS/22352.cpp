//항체인식

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int n, m, cnt, dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int ori[35][35], changed[35][35], chk[35][35];

vector<vector<pair<int,int> > > v(905);

bool safe(int y, int x){
    return y>=1&&y<=n && x>=1&&x<=m;
}

void dfs(int y, int x){
    chk[y][x] = 1;
    v[cnt].pb(mp(y,x));

    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if(safe(ny,nx) && !chk[ny][nx] && ori[ny][nx] == ori[y][x]) dfs(ny,nx);
    }
}

int main(){
    cinFast();
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> ori[i][j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> changed[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!chk[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }

    int dif = 0;
    for(int i=0; i<cnt; i++){
        int y = v[i][0].fst, x = v[i][0].snd;
        int group = changed[y][x];
        if(group != ori[y][x]) dif++;

        for(int j=1; j<v[i].size(); j++){
            y = v[i][j].fst, x = v[i][j].snd;

            if(changed[y][x] != group) return cout << "NO",0;
        }
    }
    if(dif <= 1) cout << "YES";
    else cout << "NO";
}
