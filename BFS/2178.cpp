//미로 탐색
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;


int arr[105][105], visit[105][105], n, m;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool safe(int y, int x){
    return y >= 1 && y <= n && x >= 1 && x <= m;
}

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d",&arr[i][j]);

    queue<pair<int,int> > q;
    q.push(mp(1,1));
    visit[1][1] = 1;

    while(!q.empty()){
        int y = q.front().fst;
        int x = q.front().snd;
        q.pop();

        if(y == n && x == m)
            return cout << visit[y][x],0;

        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(safe(ny,nx) && arr[ny][nx]==1 && !visit[ny][nx]){
                q.push(mp(ny,nx));
                visit[ny][nx] = visit[y][x] + 1;
            }
        }
    }
}