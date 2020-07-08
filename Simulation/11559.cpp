//Puyo Puyo
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
using namespace std;

char arr[15][10];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int chk[15][10], cnt;
queue<pair<int,int> > visit;

bool safe(int y, int x){
    return y>=1 && y<=12 && x>=1 && x<=6;
}

void drop(){
    for(int i=1; i<=6; i++){
        for(int j=12; j>=1; j--){
            if(arr[j][i] != '.'){
                int k = 12;
                while(arr[k][i] != '.' && k >= j) k--;
                if(arr[k][i] == '.'){
                    arr[k][i] = arr[j][i];
                    arr[j][i] = '.';
                }
            }
        }
    }
}

void dfs(int y, int x){
    cnt++;
    visit.push(mp(y,x));
    chk[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(!chk[ny][nx] && arr[ny][nx] == arr[y][x])
            dfs(ny,nx);
    }
}


int main(){
    for(int i=1; i<=12; i++)
        for(int j=1; j<=6; j++)
            cin >> arr[i][j];

    int ans = 0;

    while(1){
        drop();

        memset(chk,0,sizeof(chk));
        int pop = 0;

        for(int i=1; i<=12; i++){
            for(int j=1; j<=6; j++){
                if(!chk[i][j] && arr[i][j]!='.'){
                    cnt = 0;
                    dfs(i,j);
                    if(cnt >= 4) pop++;
                    while(!visit.empty()){
                        int y = visit.front().fst;
                        int x = visit.front().snd;
                        visit.pop();

                        if(cnt >= 4) arr[y][x] = '.';
                    }
                }
            }
        }

        if(pop) ans++;
        else break;
    }
    printf("%d",ans);
}
