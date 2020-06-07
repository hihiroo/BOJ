//미세먼지 안녕!
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int R,C,T, arr[55][55], puricare = 100;

bool safe(int y, int x){
    return y>0 && y<=R && x>0 && x<=C;
}

void left_to_right(int row){
    for(int i=C; i>2; i--)
        arr[row][i] = arr[row][i-1];
    arr[row][2] = 0;
}

void right_to_left(int row){
    for(int i=1; i<C; i++)
        arr[row][i] = arr[row][i+1];
}

void up(int s, int e, int col){
    for(int i=e; i<=s; i++)
        arr[i][col] = arr[i+1][col];
}

void down(int s, int e, int col){
    for(int i=e; i>=s; i--)
        arr[i][col] = arr[i-1][col];
}
void wind(){
    down(2,puricare-1,1);
    right_to_left(1);
    up(puricare-1,1,C);
    left_to_right(puricare);

    up(R-1,puricare+2,1);
    right_to_left(R);
    down(puricare+2,R,C);
    left_to_right(puricare+1);
}

void diffusion(){
    int delta[55][55];
    memset(delta,0,sizeof(delta));

    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(arr[i][j] <= 0) continue;
            int val = arr[i][j]/5;

            for(int k=0; k<4; k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];

                if(safe(ny,nx) && arr[ny][nx] != -1){
                    delta[ny][nx] += val;
                    delta[i][j] -= val;
                }
            }
        }
    }

    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            arr[i][j] += delta[i][j];
}

int main(){
    cin >> R >> C >> T;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1)
                puricare = min(puricare,i);
        }
    }

    for(int i=0; i<T; i++){
        diffusion();
        wind();
    }

    int ans = 0;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            ans += max(0,arr[i][j]);

    cout << ans;
}
