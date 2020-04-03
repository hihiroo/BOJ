//알파벳
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

int r, c, ans, visit[26], arr[21][21];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool safe(int y, int x){
    return y>=1 && y<=r && x>=1 && x<=c;
}

void dfs(int y, int x, int cnt){
    ans = max(cnt,ans);
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx) && !visit[arr[ny][nx]]){
            visit[arr[ny][nx]] = 1;
            dfs(ny,nx,cnt+1);
            visit[arr[ny][nx]] = 0;
        }
    }
    return;
}

int main(){
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char a;
            cin>>a;
            arr[i][j] = a-'A';
        }
    }
    visit[arr[1][1]] = 1;
    dfs(1,1,1);
    cout<<ans;
}
