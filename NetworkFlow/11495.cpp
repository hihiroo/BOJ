#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

vector<vector<int> > v(3000);
int f[3000][3000], c[3000][3000], arr[60][60], n, m;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool safe(int y, int x){
    return y <= n && y > 0 && x <= m && x > 0;
}

int nf(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(3000,-1);
        queue<int> q;
        q.push(s);

        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();
            
            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(c[vtx][next] - f[vtx][next] > 0 && par[next] == -1){
                    par[next] = vtx;
                    q.push(next);
                }
            }
        }
        if(par[e] == -1) break;

        int poss = 100000000;
        for(int i=e; i != s; i = par[i])
            poss = min(poss,c[par[i]][i] - f[par[i]][i]);
        
        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }

        ans += poss;
    }
    return ans;
}

int main(){
    int t, cnt;
    cin>>t;
    for(; t>0; t--){  
        cnt = 0; // 총 합
        for(int i=0; i<3000; i++) v[i].clear();
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));

        cin>>n>>m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>arr[i][j];
                cnt += arr[i][j];

                if((i+j)%2){
                    //소스랑 연결, 용량은 그 칸의 수
                    v[0].pb((i-1)*m+j);
                    v[(i-1)*m+j].pb(0);
                    c[0][(i-1)*m+j] = arr[i][j];

                    //인접 노드랑 연결, 용량은 무한
                    for(int k=0; k<4; k++){
                        int ny = i + dir[k][0];
                        int nx = j + dir[k][1];
                        if(safe(ny,nx)){
                            v[(i-1)*m+j].pb((ny-1)*m + nx);
                            v[(ny-1)*m + nx].pb((i-1)*m+j);
                            c[(i-1)*m+j][(ny-1)*m+nx] = 100000000;
                        }
                    }

                } 
                else{
                    //싱크랑 연결, 용량은 그 칸의 수
                    v[(i-1)*m+j].pb(n*m+1);
                    v[n*m+1].pb((i-1)*m+j);
                    c[(i-1)*m+j][n*m+1] = arr[i][j];
                }
            }
        }
        //최대유량 + 남아있는 수의 합
        printf("%d\n",cnt-nf(0,n*m+1));
    }
}