//열쇠
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int h,w,dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool haveKey[30], visit[105][105];
char arr[105][105];

bool safe(int y, int x){
    return y>0 && y<=h && x>0 && x<=w;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>h>>w;
        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        memset(haveKey,0,sizeof(haveKey));

        queue<pair<int,int> > q;
        vector<vector<pair<int,int> > > v(30);
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin>>arr[i][j];
                if(arr[i][j] != '*' && (i == 1 || j == 1 || i == h || j == w)){
                    visit[i][j] = 1;
                    q.push(mp(i,j));
                }
                if(arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                    v[arr[i][j]-'A'].pb(mp(i,j));
            }
        }

        string key;
        cin>>key;
        if(key != "0"){
            for(int i=0; i<key.size(); i++)
                haveKey[key[i]-'a'] = 1;
        }

        int ans = 0;
        while(!q.empty()){
            int y = q.front().fst;
            int x = q.front().snd;
            char now = arr[y][x];
            q.pop();

            if(now == '$') ans++;
            else if(now >= 'A' && now <= 'Z' && !haveKey[now-'A']) continue;
            else if(now >= 'a' && now <= 'z' && !haveKey[now-'a']){
                haveKey[now-'a'] = 1;
                for(int i=0; i<v[now-'a'].size(); i++){
                    int ny = v[now-'a'][i].fst;
                    int nx = v[now-'a'][i].snd;
                    if(visit[ny][nx]) q.push(mp(ny,nx));
                }
            }

            for(int i=0; i<4; i++){
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if(safe(ny,nx) && !visit[ny][nx] && arr[ny][nx] != '*'){
                    visit[ny][nx] = 1;
                    q.push(mp(ny,nx));
                }
            }
        }
        cout<<ans<<"\n";
    }
}
