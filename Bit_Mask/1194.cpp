//달이 차오른다, 가자
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m, visit[55][55][1<<6], keycnt, keynum[26];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
char arr[55][55];

bool safe(int y, int x){
    return y<=n && y>=1 && x>=1 && x<=m;
}

int main(){
    cinFast();
    cin >> n >> m;
    memset(keynum,-1,sizeof(keynum));

    queue<pair<int,pair<int,int> > > q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0'){
                q.push(mp(i,mp(j,0)));
                visit[i][j][0] = 1;
            }
        }
    }

    while(!q.empty()){
        int y = q.front().fst;
        int x = q.front().snd.fst;
        int cur = q.front().snd.snd;
        q.pop();

        if(arr[y][x] == '1')
            return cout << visit[y][x][cur]-1,0;

        if(arr[y][x] >= 'A' && arr[y][x] <= 'Z'){
            if(keynum[arr[y][x]] == -1) continue;
            if(cur&(1<<keynum[arr[y][x]-'A']));
            else continue;
        }

        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(!safe(ny,nx) || arr[ny][nx] == '#') continue;

            int ncur = cur;
            if(arr[ny][nx] >= 'a' && arr[ny][nx] <= 'z'){
                if(keynum[arr[ny][nx]-'a'] == -1)
                    keynum[arr[ny][nx]-'a'] = keycnt++;
                ncur |= (1<<keynum[arr[ny][nx]-'a']);
            }

            if(!visit[ny][nx][ncur]){
                visit[ny][nx][ncur] = visit[y][x][cur]+1;
                q.push(mp(ny,mp(nx,ncur)));
            }
        }
    }
    cout << -1;
}
