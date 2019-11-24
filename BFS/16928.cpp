//뱀과 사다리 게임

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define mp make_pair
#define pb push_back

vector<vector<int> > v(105);
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n+m; i++){
        int s,e;
        cin>>s>>e;
        v[s].pb(e);
    }

    priority_queue<pair<int,int> > q;
    q.push(mp(0,1));

    int visit[105] = {0,};
    while(!q.empty()){
        int cnt = -q.top().first;
        int vtx = q.top().second;
        q.pop();
        
        if(visit[vtx]) continue;
        visit[vtx] = 1;

        if(vtx == 100) return !printf("%d",cnt);
        for(int i=1; i<=6; i++){
            if(vtx + i > 100) break;
            int next = vtx + i;
            if(!visit[next]){
                if(v[next].size()) q.push(mp(-cnt-1,v[next][0]));
                else q.push(mp(-cnt-1,next));
            }
        }
    }
}