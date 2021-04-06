//세금
#include <bits/stdc++.h>
using namespace std;
#define cinFast() ios_base::sync_with_stdio(0); cin.tie();
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair

vector<vector<pair<int,int> > > v(1005);
int dist[1005][1005];

int main(){
    cinFast();
    int n,m,k;
    cin >> n >> m >> k;

    int s,d;
    cin >> s >> d;

    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;

        v[a].pb({b,w});
        v[b].pb({a,w});
    }

    vector<int> p(k+1);
    for(int i=1; i<=k; i++){
        cin >> p[i];
        p[i] += p[i-1];
    }

    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(mp(0,mp(0,s)));
    memset(dist,-1,sizeof(dist));

    while(!pq.empty()){
        int cost = -pq.top().fst;
        int vtx = pq.top().snd.snd;
        int cnt = pq.top().snd.fst;
        pq.pop();

        if(dist[cnt][vtx] != -1) continue;
        dist[cnt][vtx] = cost;
        if(vtx == d) continue;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int total = cost + v[vtx][i].snd;

            bool pass = 0;
            for(int j=0; j<=cnt; j++){
                if(j<=cnt+1 && dist[j][next]!= -1 && dist[j][next]<=total){
                    pass = 1;
                    break;
                }
            }
            if(!pass) pq.push(mp(-total,mp(cnt+1,next)));
        }
    }

    for(int i=0; i<=k; i++){ // 세금 인상 횟수
        int ans = 1e9;
        for(int cnt=0; cnt<n; cnt++){ // 지나간 도로 개수
            if(dist[cnt][d] == -1) continue;
            ans = min(ans,dist[cnt][d]+p[i]*cnt);
        }
        cout << ans << '\n';
    }
}
