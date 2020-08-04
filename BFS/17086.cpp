//아기상어2
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n, m, dist[55][55], arr[55][55];

bool safe(int y, int x){
    return y>=0 && y<n && x>=0 && x<m;
}

int main(){
    cin >> n >> m;
    memset(dist,-1,sizeof(dist));

    queue<pair<int,int> > q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                dist[i][j] = 0;
                q.push(mp(i,j));
            }
        }
    }

    int ans = 0;
    while(!q.empty()){
        int y = q.front().fst;
        int x = q.front().snd;
        q.pop();

        ans = max(ans,dist[y][x]);

        int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},
                {1,1},{1,-1},{-1,1},{-1,-1}};

        for(int i=0; i<8; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(safe(ny,nx) && dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] + 1;
                q.push(mp(ny,nx));
            }
        }
    }
    cout << ans;
}
