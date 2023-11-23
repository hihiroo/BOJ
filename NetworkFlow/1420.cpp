#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}}, block[105][105];
int level[20005], idx[20005];

struct E{
    int next, c, f;
    E* rev;

    E(int next, int c, int f): next(next), c(c), f(f){}

    int canFlow(){
        return c - f;
    }
    void makeFlow(int poss){
        f += poss;
        rev->f -= poss;
    }
};

vector<vector<E*> > v(20005);

bool bfs(int s, int e){
    memset(level, -1, sizeof(level));

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i]->next;
            if(level[next] == -1 && v[vtx][i]->canFlow()){
                level[next] = level[vtx] + 1;
                q.push(next);
            }
        }
    }
    return level[e] != -1;
}

int dfs(int vtx, int e, int flow){
    if(vtx == e) return flow;

    for(int &i=idx[vtx]; i<v[vtx].size(); i++){
        int next = v[vtx][i]->next;
        if(level[next] == level[vtx]+1 && v[vtx][i]->canFlow()){
            int poss = dfs(next, e, min(flow,v[vtx][i]->canFlow()));
            if(poss){
                v[vtx][i]->makeFlow(poss);
                return poss;
            }
        }
    }
    return 0;
}

int solve(int s, int e){
    int ans = 0;
    while(bfs(s,e)){
        memset(idx, 0, sizeof(idx));
        while(1){
            int poss = dfs(s,e,1e9);
            if(poss == 0) break;
            ans += poss;
        }
    }

    if(ans >= 1e9) return -1;
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    int s, e;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin >> a;

            if(a == 'K') s = i*m+j;
            else if(a == 'H') e = i*m+j;
            else if(a == '#') block[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int idx = i*m + j;

            E *uv = new E(idx + n*m, 1, 0); // (i,j) -> (i,j)'
            E *vu = new E(idx, 0, 0);
            uv->rev = vu, vu->rev = uv;

            if(idx == s || idx == e) uv->c = 1e9;
            v[idx].push_back(uv);
            v[idx+n*m].push_back(vu);

            for(int k=0; k<4; k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                int nidx = ny*m + nx;

                if(ny >= 0 && ny < n && nx >= 0 && nx < m && !block[ny][nx]){
                    E *edge = new E(nidx, 1e9, 0);
                    E *revE = new E(idx+n*m, 0, 0);
                    edge->rev = revE, revE->rev = edge;

                    v[idx+n*m].push_back(edge);
                    v[nidx].push_back(revE);
                }
            }
        }
    }
    cout << solve(s,e+n*m) << '\n';
}