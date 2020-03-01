//로봇청소기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int n,m, arr[55][55], visit[55][55],ans=1;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//북 = 0, 서쪽은 1, 남쪽은 2, 동쪽은 3

void f(int y, int x, int d){
    bool IspossC = false;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(arr[ny][nx] == 0){
            IspossC = true;
            break;
        }
    }
    if(!IspossC){ // 네방향 모두 청소 불가
        int back_num = (d + 2)%4;
        int ny = y + dir[back_num][0];
        int nx = x + dir[back_num][1];
        if(arr[ny][nx] == 1) return;
        f(ny,nx,d);
        return;
    }

    int left_num = (d+1)%4;
    int ny = y + dir[left_num][0];
    int nx = x + dir[left_num][1];

    if(arr[ny][nx] == 0){
        arr[ny][nx] = 2;
        ans++;
        f(ny,nx,left_num);
    }
    else f(y,x,left_num);
}

int main(){
    cin>>n>>m;
    int r,c,d;
    cin>>r>>c>>d;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&arr[i][j]);

    arr[r][c] = 2;
    if(d == 0 || d == 2) f(r,c,d);
    else if(d == 1) f(r,c,3);
    else f(r,c,1);

    cout<<ans;
}
