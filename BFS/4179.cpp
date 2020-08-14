//불!
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int fire[1005][1005], visit[1005][1005], n,m;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char arr[1005][1005];

bool safe(int y, int x){
    return y<=n && y>=1 && x<=m && x>=1;
}

int main(){
    cin >> n >> m;

    queue<pair<int,int> > q, qq;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'F'){
                fire[i][j] = 1;
                q.push(mp(i,j));
            }
            else if(arr[i][j] == 'J'){
                visit[i][j] = 1;
                qq.push(mp(i,j));
            }
        }
    }

    while(!q.empty()){
        int y = q.front().fst;
        int x = q.front().snd;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(safe(ny,nx) && !fire[ny][nx] && arr[ny][nx] != '#'){
                fire[ny][nx] = fire[y][x] + 1;
                q.push(mp(ny,nx));
            }
        }
    }

    while(!qq.empty()){
        int y = qq.front().fst;
        int x = qq.front().snd;
        qq.pop();

        if(y == n || y == 1 || x == 1 || x == m)
            return cout << visit[y][x],0;

        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(!safe(ny,nx) || visit[ny][nx] || arr[ny][nx] == '#') continue;
            if(fire[ny][nx] > visit[y][x]+1 || !fire[ny][nx]){
                visit[ny][nx] = visit[y][x]+1;
                qq.push(mp(ny,nx));
            }
        }
    }

    cout << "IMPOSSIBLE";
}
