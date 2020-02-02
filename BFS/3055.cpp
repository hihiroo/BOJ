//탈출

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


int r,c, soak[51][51], visit[51][51];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char arr[51][51];

bool safe(int y, int x){
    return y >= 1 && y <= r && x >= 1 && x <= c;
}

int main(){
    memset(soak,-1,sizeof(soak));
    memset(visit,-1,sizeof(visit));
    cin>>r>>c;

    queue<pair<int,int> > s,q;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'S'){
                visit[i][j] = 0;
                q.push(mp(i,j));
            }
            else if(arr[i][j] == '*'){
                soak[i][j] = 0;
                s.push(mp(i,j));
            }
        }
    }
    while(!s.empty()){
        int y = s.front().fst;
        int x = s.front().snd;
        s.pop();

        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(safe(ny,nx) && soak[ny][nx] == -1){
                if(arr[ny][nx] == '.' || arr[ny][nx] == 'S'){
                    soak[ny][nx] = soak[y][x] + 1;
                    s.push(mp(ny,nx));
                }
            }
        }
    }
    while(!q.empty()){
        int y = q.front().fst;
        int x = q.front().snd;
        q.pop();

        if(arr[y][x] == 'D') return cout<<visit[y][x],0;
        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(safe(ny,nx) && visit[ny][nx] == -1){
                if(arr[ny][nx] == '*' || arr[ny][nx] == 'X')
                    continue;
                if(soak[ny][nx] == -1 || visit[y][x] + 1 < soak[ny][nx]){
                    visit[ny][nx] = visit[y][x] + 1;
                    q.push(mp(ny,nx));
                }
            }
        }

    }
    return cout<<"KAKTUS",0;
}

