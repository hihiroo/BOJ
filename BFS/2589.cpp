//보물섬

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second


char arr[55][55];
int n,m,dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool safe(int y, int x){
    return y > 0 && y <= n && x > 0 && x <= m;
}

int visit[55][55];

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] == 'W') continue;
            memset(visit,-1,sizeof(visit));

            queue<pair<int,int> > q;
            q.push(mp(i,j));
            visit[i][j] = 0;
            
            while(!q.empty()){
                int y = q.front().fst;
                int x = q.front().snd;
                q.pop();
                
                
                for(int k=0; k<4; k++){
                    int ny = y + dir[k][0];
                    int nx = x + dir[k][1];
                    if(safe(ny,nx) && visit[ny][nx] == -1 && arr[ny][nx] == 'L'){
                        visit[ny][nx] = visit[y][x] + 1;
                        ans = max(ans,visit[ny][nx]);
                        q.push(mp(ny,nx));
                    }
                }
            }
        }
    }
    cout<<ans; 
}