// 거의 최단 경로

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int main(){
    int n,m,u,v,p,s,d;
    while(1){
        vector<vector<pair<int,int> > > vtx(501);
        vector<vector<pair<int,pair<int,int> > > > save(501);
        int ans = -1;
        cin>>n>>m;
        if(n==0 && m==0) return 0;
        cin>>s>>d;
        for(int i=0; i<m; i++){
            cin>>u>>v>>p;
            vtx[u].pb(mp(v,p));
        }
        priority_queue <pair<int,pair<int,int> > > q;
        int vertex,cost,pre,idx;
        bool chk=false;
        save[s].pb(mp(0,mp(-1,-1)));
        for(int i=0; i<vtx[s].size(); i++)
            q.push(mp(-vtx[s][i].second,mp(i,s)));
        while(!q.empty()){
            pre = q.top().second.second;
            idx = q.top().second.first;
            vertex = vtx[pre][idx].first;
            cost = -q.top().first;
            if(chk && vertex != d) break;
            if(chk && cost != save[d][0].first) break;
            q.pop();
            if(save[vertex].size()){
                if(save[vertex][0].first == cost)
                    save[vertex].pb(mp(cost,mp(pre,idx)));
                else continue;
            }
            else save[vertex].pb(mp(cost,mp(pre,idx)));
            if(vertex == d){
                chk = true;
                continue;
            }
            for(int i=0; i<vtx[vertex].size(); i++){
                if(save[vtx[vertex][i].first].size()>0)
                    if(save[vtx[vertex][i].first][0].first < cost+vtx[vertex][i].second)
                        continue;
                q.push(mp(-(cost+vtx[vertex][i].second),mp(i,vertex)));
            }
        }
        queue<int> del;
        del.push(d);
        while(!del.empty()){
            vertex = del.front();
            del.pop();
            if(vertex == s) continue;
            for(int i=0; i<save[vertex].size(); i++){
                int pre = save[vertex][i].second.first;
                int idx = save[vertex][i].second.second;
                vtx[pre][idx].second = -1;
                del.push(pre);
            }
        }
        priority_queue <pair<int,int> > nq;
        int dij[501];
        fill(dij,dij+501,-1);
        nq.push(mp(0,s));
        while(!nq.empty()){
            vertex = nq.top().second;
            cost  = -nq.top().first;
            dij[vertex] = cost;
            nq.pop();
            if(vertex == d){
                ans = cost;
                break;
            }
            for(int i=0; i<vtx[vertex].size(); i++){
                if(vtx[vertex][i].second != -1){
                    if(dij[vtx[vertex][i].first] != -1) continue;
                    nq.push(mp(-vtx[vertex][i].second-cost,vtx[vertex][i].first));
                }
            }
        }
        printf("%d\n",ans);
    }
}



