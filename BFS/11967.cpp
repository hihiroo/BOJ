#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[105][105];
int visited[105][105], flash[105][105];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a,b});
    }

    queue<pair<int,int> > q;
    q.push({1,1});
    visited[1][1] = 1, flash[1][1] = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(!flash[y][x]) continue;
        for(int i=0; i<v[y][x].size(); i++){
            int ny = v[y][x][i].first;
            int nx = v[y][x][i].second;
            if(!flash[ny][nx] && visited[ny][nx]){
                q.push({ny,nx});
            }
            flash[ny][nx] = 1;
        }

        int dir[4][2] = {{-1,0}, {0,1}, {0,-1}, {1,0}};
        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(ny > 0 && ny <= n && nx > 0 && nx <= n){
                if(!visited[ny][nx]){
                    visited[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(flash[i][j]) ans++;

    cout << ans << '\n';
}