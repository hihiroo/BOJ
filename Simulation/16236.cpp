//아기 상어
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int arr[25][25], n, dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int visit[25][25];

bool safe(int y, int x){
    return y>0 && y<=n && x>0 && x<=n;
}

int main(){
    cin>>n;
    int sharkY, sharkX;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 9){
                sharkY = i;
                sharkX = j;
            }
        }
    }

    int size = 2, cnt = 0, time = 0;

    while(1){
        arr[sharkY][sharkX] = 0;

        memset(visit,-1,sizeof(visit));
        queue<pair<int,int> > q;
        q.push(mp(sharkY,sharkX));
        visit[sharkY][sharkX] = 0;

        vector<pair<int,pair<int,int> > > fish;

        while(!q.empty()){
            int y = q.front().fst;
            int x = q.front().snd;
            q.pop();

            if(arr[y][x] && arr[y][x] < size)
                fish.pb(mp(visit[y][x],mp(y,x)));

            for(int i=0; i<4; i++){
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if(safe(ny,nx) && visit[ny][nx] == -1 && arr[ny][nx] <= size){
                    visit[ny][nx] = visit[y][x]+1;
                    q.push(mp(ny,nx));
                }
            }
        }

        if(!fish.size()) return cout<<time,0;

        sort(fish.begin(),fish.end());
        time += fish[0].fst;
        sharkY = fish[0].snd.fst;
        sharkX = fish[0].snd.snd;

        if(++cnt == size){
            size++;
            cnt = 0;
        }
    }

}
