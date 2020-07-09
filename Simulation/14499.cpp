//주사위 굴리기
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, m, arr[25][25];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
vector<int> LR(4), UD(4);
//      0          동서쪽 회전은 A B C D 로테이션
// 4(A) 1(B) 5(C)  남북쪽 회전은 0 1 2 3 로테이션
//      2
//      3(D)

bool safe(int y, int x){
    return y>=0&&y<n && x>=0&&x<m;
}

void rotateLR(bool L){
    if(L) rotate(LR.begin(),LR.begin()+1,LR.end());
    else rotate(LR.rbegin(),LR.rbegin()+1,LR.rend());
    UD[1] = LR[1], UD[3] = LR[3];
}

void rotateUD(bool U){
    if(U) rotate(UD.begin(),UD.begin()+1,UD.end());
    else rotate(UD.rbegin(),UD.rbegin()+1,UD.rend());
    LR[1] = UD[1], LR[3] = UD[3];
}

int main(){
    cinFast();

    int y, x, k;
    cin >> n >> m >> y >> x >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> arr[i][j];

    while(k--){
        int d;
        cin >> d;

        int ny = y + dir[d-1][0];
        int nx = x + dir[d-1][1];
        if(!safe(ny,nx)) continue;

        y = ny, x = nx;
        if(d == 1) rotateLR(0);
        else if(d == 2) rotateLR(1);
        else rotateUD(d%2);

        // 주사위 바닥면 = UD[3], LR[3]
        if(arr[y][x] == 0) arr[y][x] = UD[3];
        else{
            UD[3] = arr[y][x], LR[3] = arr[y][x];
            arr[y][x] = 0;
        }

        cout << UD[1] << '\n';
    }
}
