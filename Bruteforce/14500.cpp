//테트로미노
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n,m,arr[505][505],ans;
int visit[505][505], dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool safe(int y, int x){
    return y>0 && y<=n && x>0 && x<=m;
}

void cross(int y, int x){
    int sum = arr[y][x];
    int poss = 0;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx)){
            poss++;
            sum += arr[ny][nx];
        }
    }
    if(poss == 3) ans = max(ans,sum);
    else if(poss == 4){
        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            ans = max(ans,sum-arr[ny][nx]);
        }
    }
}

void dfs(int y, int x, int cnt, int sum){
    sum += arr[y][x];
    if(cnt == 4){
        ans = max(ans,sum);
        return;
    }

    visit[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx) && !visit[ny][nx])
            dfs(ny,nx,cnt+1,sum);
    }
    visit[y][x] = 0;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin>>arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dfs(i,j,1,0);
            cross(i,j);
        }
    }

    cout<<ans;
}

