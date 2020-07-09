// 어른 상어
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n,m,k, arr[25][25], smell[25][25], sT[25][25];
int dir[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}};

bool safe(int y, int x){
    return y>=1 && y<=n && x<=n && x>=1;
}

struct Fish{
    int y, x, curDir, idx, dOrder[5][5];
    bool getOut;

    void init(int a, int b, int c){
        y = a, x = b, idx = c;
        arr[a][b] = c, getOut = false;
        smell[a][b] = c, sT[a][b] = k;
    }

    void getPriority(){
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
                cin >> dOrder[i][j];
    }

    bool posi(int a, int b, int d){
        arr[y][x] = 0;
        curDir = d, y = a, x = b;

        if(arr[a][b] && arr[a][b] < idx){
            getOut = true;
            return false;
        }

        arr[a][b] = idx;
        return true;
    }

    void spread(){
        if(getOut) return;
        smell[y][x] = idx, sT[y][x] = k;
    }

    bool move(){
        if(getOut) return false;

        int nny = 0, nnx = 0, nnd = 0;
        for(int i=1; i<=4; i++){
            int nD = dOrder[curDir][i];
            int ny = y + dir[nD][0];
            int nx = x + dir[nD][1];

            if(!safe(ny,nx)) continue;

            if(smell[ny][nx] == 0) return posi(ny,nx,nD);

            if(smell[ny][nx] == idx){
                if(nny) continue;
                nny = ny, nnx = nx, nnd = nD;
            }
        }
        return posi(nny,nnx,nnd);
    }
}shark[405];

int main(){
    cinFast();
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int s,j=1; j<=n; j++){
            cin >> s;
            shark[s].init(i,j,s);
        }
    }

    for(int i=1; i<=m; i++) cin >> shark[i].curDir;
    for(int i=1; i<=m; i++) shark[i].getPriority();

    int time = 0;
    while(time++ < 1000){
        int remain = 0;

        for(int i=1; i<=m; i++)
            remain += shark[i].move();

        if(remain == 1) return cout << time,0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                sT[i][j] = max(0,sT[i][j]-1);
                if(sT[i][j] == 0) smell[i][j] = 0;
            }
        }

        for(int i=1; i<=m; i++) shark[i].spread();
    }
    cout << -1;
}