//뱀
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n, arr[105][105], finish, t;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool safe(int y, int x){
    return y>0 && y<=n && x>0 && x<=n;
}

struct snake{
    queue<pair<int,int> > q;
    int hy, hx, d;

    snake(int x): hy(1),hx(1){
        q.push(mp(1,1));
        arr[1][1] = 2, d = 0;
    }

    void changeD(char c){
        if(c == 'D') d = (d+1)%4;
        else d = (d-1+4)%4;
    }

    void move(){
        int nr = hy + dir[d][0];
        int nc = hx + dir[d][1];

        if(!safe(nr,nc) || arr[nr][nc] == 2){
            finish = t;
            return;
        }

        if(arr[nr][nc] == 1);
        else{ // 사과 없으면 꼬리 pop
            int y = q.front().fst;
            int x = q.front().snd;
            q.pop();
            arr[y][x] = 0;
        }

        q.push(mp(nr,nc));
        hy = nr, hx = nc;
        arr[nr][nc] = 2;
    }
};

int main(){
    cinFast();
    cin >> n;
    snake bam(0);

    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        int r,c;
        cin >> r >> c;
        arr[r][c] = 1;
    }

    int l;
    cin >> l;

    for(int i=0; i<l; i++){
        int x;
        char c;
        cin >> x >> c;

        while(!finish && t++ < x) bam.move();
        bam.changeD(c);
        if(!finish) bam.move();
    }

    while(!finish && ++t) bam.move();
    cout << finish;
}
