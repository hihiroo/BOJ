//청소년 상어
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct Fish{
    int num, d;
    Fish(): num(),d(){cin >> num >> d; --d;}
};

bool safe(int y, int x){
    return y<4 && y>=0 && x>=0 && x<4;
}

int ans, dir[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},
                    {1,0},{1,1},{0,1},{-1,1}};

void moveFish(int Sy, int Sx, vector<vector<Fish> >& v){
    vector<pair<int,int> > coordi(17,mp(-1,-1));

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            coordi[v[i][j].num] = mp(i,j);

    for(int i=1; i<=16; i++){
        int y = coordi[i].fst, x = coordi[i].snd;
        if(y == -1) continue; // 잡아 먹힌 물고기 패스

        for(int k=0; k<8; k++){
            v[y][x].d = (v[y][x].d+1)%8;
            int ny = y + dir[nd][0];
            int nx = x + dir[nd][1];

            if(!safe(ny,nx) || (ny==Sy && nx==Sx))
                continue; // 이동 못하는 칸 패스

            int obj = v[ny][nx].num;
            swap(v[y][x],v[ny][nx]);
            swap(coordi[i],coordi[obj]);
            break;
        }
    }
}


void f(int y, int x, int cnt, vector<vector<Fish> > v){
    cnt += v[y][x].num; //상어 이동 후 물고기 꿀꺽
    v[y][x].num = 0; // 빈칸으로 바뀜

    moveFish(y,x,v); // 물고기 대이동

    bool canMove = 0; // 상어는 과연 멈출것인가

    int d = v[y][x].d; // 상어 방향
    while(1){
        y += dir[d][0];
        x += dir[d][1];
        if(!safe(y,x)) break; //더이상 못가

        if(v[y][x].num == 0) continue; //빈칸 못가

        f(y,x,cnt,v);
        canMove = 1;
    }

    if(!canMove) ans = max(ans,cnt);
}

int main(){
    cinFast();

    vector<vector<Fish> > v(5);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) v[i].pb(Fish());

    f(0,0,0,v);
    cout << ans;
}
