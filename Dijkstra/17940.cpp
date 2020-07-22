//지하철
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<pair<int,int> > >v(1005);
int company[1005], visit[1005];
int cost[1005][1005];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> company[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cost;
            cin >> cost;
            if(cost) v[i].pb(mp(j,cost));
        }
    }

    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,0));

    int k = 0;
    while(!pq.empty()){
        int vtx = pq.top().snd;
        int change = -pq.top().fst;
        pq.pop();

        if(visit[vtx]) continue;
        visit[vtx] = 1;

        if(vtx == m){
            k = change;
            break;
        }

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int ncost = change + (company[vtx] != company[next]);

            if(visit[next]) continue;
            pq.push(mp(-ncost,next));
        }
    }

    priority_queue<pair<int,pair<int,int> > > ppq;
    ppq.push(mp(0,mp(0,0)));

    while(!ppq.empty()){
        int c = -ppq.top().fst;
        int vtx = ppq.top().snd.snd;
        int change = ppq.top().snd.fst;
        ppq.pop();

        if(cost[change][vtx]) continue;
        cost[change][vtx] = 1;

        if(vtx == m && change == k)
            return cout << k << " " << c,0;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int ncost = c + v[vtx][i].snd;
            int cnt = change + (company[vtx]!=company[next]);

            if(!cost[change][next] && cnt <= k)
                ppq.push(mp(-ncost,mp(cnt,next)));
        }
    }
}
