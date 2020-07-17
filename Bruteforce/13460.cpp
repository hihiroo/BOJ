//구슬 탈출2
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

#define box vector<vector<char> >
int n, m, Ry, Rx, By, Bx, ans = 11;
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

namespace escape{
    bool move(box &arr, char beed, int d, int &y, int &x){
        int dy = dir[d][0], dx = dir[d][1];

        while(arr[y+dy][x+dx] == '.'){
            arr[y][x] = '.', arr[y+dy][x+dx] = beed;
            y += dy, x += dx;
        }
        if(arr[y+dy][x+dx] == 'O'){
            arr[y][x] = '.';
            return true;
        }
        return false;
    }

    int tilt(box &arr, int d){//성공하면 1, 실패하면 -1, 안끝났으면 0
        bool isBfirst = false;

        if(d == 0 && By == Ry && Bx < Rx) isBfirst = 1;
        if(d == 1 && By == Ry && Bx > Rx) isBfirst = 1;
        if(d == 2 && Bx == Rx && By < Ry) isBfirst = 1;
        if(d == 3 && Bx == Rx && By > Ry) isBfirst = 1;

        if(isBfirst){
            if(move(arr,'B',d,By,Bx)) return -1;
            if(move(arr,'R',d,Ry,Rx)) return 1;
            return 0;
        }

        if(move(arr,'R',d,Ry,Rx)){
            if(move(arr,'B',d,By,Bx)) return -1;
            return 1;
        }
        if(move(arr,'B',d,By,Bx)) return -1;
        return 0;
    }
}

void f(box arr, int cnt, int d){
    int y = Ry, x = Rx, yy = By, xx = Bx;

    int finish = escape::tilt(arr,d);

    if(finish == 1) ans = min(ans, cnt);
    else if(finish == -1);
    else if(cnt != 10)
        for(int i=0; i<4; i++)
            if(d != i) f(arr,cnt+1,i);

    Ry = y, Rx = x, By = yy, Bx = xx;
}

int main(){
    cinFast();
    cin >> n >> m;

    box arr(10);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin >> a;
            arr[i].pb(a);

            if(a == 'R') Ry = i, Rx = j;
            if(a == 'B') By = i, Bx = j;
        }
    }

    for(int i=0; i<4; i++) f(arr,1,i);

    if(ans == 11) return cout << -1,0;
    else return cout << ans,0;
}
