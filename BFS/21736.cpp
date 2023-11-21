#include <bits/stdc++.h>
using namespace std;

int arr[606][606], chk[606][606];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    queue<pair<int,int> > q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin >> a;

            if(a == 'I'){
                chk[i][j] = 1;
                q.push({i,j});
            }
            else if(a == 'X') chk[i][j] = 1;
            else if(a == 'P') arr[i][j] = 1;
        }
    }

    int ans = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(arr[y][x]) ans++;

        int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int i=0; i<4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(ny >= 0 && ny < n && nx >=0 && nx < m){
                if(chk[ny][nx] == 0){
                    chk[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
    }

    if(ans) cout << ans;
    else cout << "TT";
}