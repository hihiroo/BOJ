#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v(505);
int lv[505], idx[505];
long long c[505][505], f[505][505];

bool bfs(int s, int e){
    memset(lv, -1, sizeof(lv));
    queue<int> q;
    
    q.push(s);
    lv[s] = 0;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(lv[next] == -1 && c[vtx][next] > f[vtx][next]){
                lv[next] = lv[vtx] + 1;
                q.push(next);
            }
        }
    }
    return lv[e] != -1;
}

long long dfs(int vtx, int e, long long minflow){
    if(vtx == e) return minflow;
    
    for(int &i=idx[vtx]; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(lv[next] == lv[vtx]+1 && c[vtx][next] > f[vtx][next]){
            long long poss = dfs(next, e, min(minflow, c[vtx][next]-f[vtx][next]));
            if(poss){
                f[vtx][next] += poss;
                f[next][vtx] -= poss;
                return poss;
            }
        }
    }
    return 0;
}

long long flow(int s, int e){
    long long ans = 0;
    while(bfs(s,e)){
        memset(idx, 0, sizeof(idx));
        while(1){
            long long poss = dfs(s,e,1e15); // 가능한 경로 찾기
            if(poss == 0) break; // 현재 lv에서 가능한 경로 없으면 break
            ans += poss;
        }
    }
    return ans;
}

int main(){
    using namespace std;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int ab;
        cin >> ab;
        if(ab == 1){
            v[0].push_back(i);
            v[i].push_back(0);
            c[0][i] = 1e15;
        }
        else if(ab == 2){
            v[i].push_back(n+1);
            v[n+1].push_back(i);
            c[i][n+1] = 1e15;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
            if(c[i][j]) v[i].push_back(j);
        }
    }

    cout << flow(0,n+1) << '\n';

    vector<bool> chk(505);
    queue<int> q;
    q.push(0);
    chk[0] = true;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(!chk[next] && c[vtx][next] > f[vtx][next]){
                chk[next] = true;
                q.push(next);
            }
        }
    }

    for(int i=1; i<=n; i++) if(chk[i]) cout << i << " ";
    cout << '\n';
    for(int i=1; i<=n; i++) if(!chk[i]) cout << i << " ";
    cout << '\n';
}