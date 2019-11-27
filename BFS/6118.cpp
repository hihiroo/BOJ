// 숨바꼭질

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lli long long
#define snd second
#define fst first


vector<vector<int> > v(20005);
bool visit[20005];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        v[s].pb(e);
        v[e].pb(s);
    }

    queue<pair<int,int> > q;
    q.push(mp(0,1));
    visit[1] = 1;
    
    int ans = 0, ans_i = 1000000000, ans_cnt = 1;
    while(!q.empty()){
        int cnt = q.front().fst;
        int vtx = q.front().snd;
        q.pop();

        if(ans < cnt){
            ans = cnt;
            ans_i = vtx;
            ans_cnt = 1;
        }
        else if(ans == cnt){
            ans_i = min(ans_i,vtx);
            ans_cnt++;
        }

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(!visit[next]){
                visit[next] = 1;
                q.push(mp(cnt+1,next));
            }
        }
    }
    printf("%d %d %d\n",ans_i,ans,ans_cnt);
}