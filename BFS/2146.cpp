//다리 만들기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

int n, cnt = 1, arr[105][105];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool safe(int y, int x){
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

void dfs(int y, int x){
    arr[y][x] = cnt;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx) && arr[ny][nx] == 1)
            dfs(ny,nx);
    }
    return;
}

int visit[101][101];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!arr[i][j]) continue;
            if(arr[i][j] == 1){
                cnt++;
                dfs(i,j);
            }
        }
    }

    queue<pair<int,int> > q;
    int ans = 1000000;
    for(int k=2; k<=cnt; k++){
        while(!q.empty()) q.pop();
        memset(visit,-1,sizeof(visit));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] != k) continue;
                visit[i][j] = 0;
                q.push(mp(i,j));
            }
        }

        while(!q.empty()){
            int y = q.front().fst;
            int x = q.front().snd;
            q.pop();

            if(arr[y][x] && arr[y][x] != k){
                ans = min(ans,visit[y][x]);
                break;
            }

            for(int i=0; i<4; i++){
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if(safe(ny,nx) && visit[ny][nx] == -1){
                    visit[ny][nx] = visit[y][x]+1;
                    q.push(mp(ny,nx));
                }
            }
        }
    }
    cout<<ans-1;
}
