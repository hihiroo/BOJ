#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back


vector<vector<int> > v(10005), ans(10005);
int visited[10005], finished[10005];
int cnt_componentd, num;
stack<int> s;


int dfs(int vtx){
    s.push(vtx);
    visited[vtx] = ++num;

    int poss = visited[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visited[next]) poss = min(poss,dfs(next));
        else if(!finished[next]) poss = min(poss,visited[next]);
    }

    if(poss == visited[vtx]){
        cnt_componentd++;
        while(1){
            int component_vtx = s.top();
            s.pop();
            finished[component_vtx] = cnt_componentd;
            ans[cnt_componentd].pb(component_vtx);
            if(component_vtx == vtx) break;
        }
        sort(ans[cnt_componentd].begin(),ans[cnt_componentd].end());
    }

    return poss;
}

int main(){
    int V,E;
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
    }
    
    for(int i=1; i<=V; i++){
        if(visited[i]) continue;
        dfs(i);
    }

    sort(ans.begin()+1,ans.begin()+cnt_componentd+1);
    
    printf("%d\n",cnt_componentd);
    for(int i=1; i<=cnt_componentd; i++){
        for(int j=0; j<ans[i].size(); j++) printf("%d ",ans[i][j]);
        printf("-1\n");
    }
}