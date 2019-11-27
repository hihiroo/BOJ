// 숨바꼭질4

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int visit[200005];

int main(){
    int n,k;
    cin>>n>>k;
    
    memset(visit,-1,sizeof(visit));

    queue<int> q;
    q.push(n);
    visit[n] = n;
    
    while(!q.empty()){
        int vtx = q.front();
        q.pop();
        
        if(vtx == k) break;

        if(vtx*2 < 200000 && visit[vtx*2] == -1){
            visit[vtx*2] = vtx;
            q.push(vtx*2);
        } 
        if(visit[vtx+1] == -1){
            visit[vtx+1] = vtx;
            q.push(vtx+1);
        }
        if(vtx-1 >= 0 && visit[vtx-1] == -1){
            visit[vtx-1] = vtx;
            q.push(vtx-1);
        }
    }
    vector<int> ans;
  
    for(int i=k; visit[i] != i; i = visit[i]) ans.pb(i);
    
    printf("%d\n%d ",ans.size(),n);
    for(int i=ans.size()-1; i>=0; i--) printf("%d ",ans[i]);
}