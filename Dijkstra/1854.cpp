// K번째 최단경로 찾기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<pair<int,int> > > v(1005);
int dist[105][1005], cnt[1005];

int main(){
    cinFast();

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].pb({b,c});
    }

    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,1));
    memset(dist,-1,sizeof(dist));

    while(!pq.empty()){
        int vtx = pq.top().snd;
        int cost = -pq.top().fst;
        pq.pop();

        cnt[vtx]++;
        if(cnt[vtx] > k) continue;
        dist[cnt[vtx]][vtx] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int total = v[vtx][i].snd + cost;

            if(cnt[next]+1 <= k) pq.push(mp(-total,next));
        }
    }

    for(int i=1; i<=n; i++)
        cout << dist[k][i] << '\n';
}
