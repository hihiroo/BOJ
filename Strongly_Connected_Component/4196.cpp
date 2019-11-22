#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long

vector<vector<int> > v(100005);
int visited[100005], n, m, cnt_component, num;
int finished[100005], indegree[100005];
stack <int> s;

int scc(int vtx){
    s.push(vtx);
    visited[vtx] = num;
    
    int can_go = num++;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visited[next]) can_go = min(can_go, scc(next)); //방문안한 자식노드
        else if(!finished[next]) can_go = min(can_go,visited[next]);
    }
    if(can_go == visited[vtx]){
        cnt_component++;
        while(1){
            int compo_vtx = s.top();
            s.pop();
            finished[compo_vtx] = cnt_component;
            if(compo_vtx == vtx) break;
        }
    }
    return can_go;
}

void reset(){
    cnt_component = 0, num = 1;
    for (int i = 1; i <= n; i++){
        v[i].clear();
        finished[i] = 0;
        visited[i] = 0;
        indegree[i] = 0;
    }
    while(!s.empty()) s.pop();
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        cin>>n>>m;
        reset();
        
        int s,e;
        for(int i=0; i<m; i++){
            cin>>s>>e;
            v[s].pb(e);
        }

        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            scc(i);
        }

       
        for(int i=1; i<=n; i++){
            for(int j=0; j<v[i].size(); j++){
                int next = v[i][j];
                if(finished[i] == finished[next]) continue;
                indegree[finished[next]] = 1;
            }
        }

        int ans = 0;
        for(int i=1; i<=cnt_component; i++)
            if(!indegree[i]) ans++;
        cout<<ans<<'\n';
    }
}