//집 구하기
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<pair<lli,lli> > > v(10005);
vector<pair<lli,lli> > visit(10005,mp(-1,-1));

int main(){
    cinFast();
    lli n,m;
    cin >> n >> m;

    for(lli i=0; i<m; i++){
        lli a,b,c;
        cin >> a >> b >> c;
        v[a].pb(mp(b,c)), v[b].pb(mp(a,c));
    }

    lli mac, x, star, y;
    cin >> mac >> x;

    priority_queue<pair<lli,lli> > pq;
    for(lli i=0,a; i<mac; i++){
        cin >> a;
        pq.push(mp(0,a));
    }

    while(!pq.empty()){
        lli vtx = pq.top().snd;
        lli cost = -pq.top().fst;
        pq.pop();

        if(visit[vtx].fst != -1) continue;
        visit[vtx].fst = cost;

        for(int i=0; i<v[vtx].size(); i++){
            lli next = v[vtx][i].fst;
            lli c = v[vtx][i].snd+cost;

            if(visit[next].fst == -1 && c <= x)
                pq.push(mp(-c,next));
        }
    }

    cin >> star >> y;
    for(lli i=0,a; i<star; i++){
        cin >> a;
        pq.push(mp(0,a));
    }

    while(!pq.empty()){
        lli vtx = pq.top().snd;
        lli cost = -pq.top().fst;
        pq.pop();

        if(visit[vtx].snd != -1) continue;
        visit[vtx].snd = cost;

        for(int i=0; i<v[vtx].size(); i++){
            lli next = v[vtx][i].fst;
            lli c = v[vtx][i].snd+cost;

            if(visit[next].snd == -1 && c <= y)
                pq.push(mp(-c,next));
        }
    }

    lli ans = 1e10;
    for(lli i=1; i<=n; i++){
        if(visit[i].fst < 1 || visit[i].snd < 1) continue;
        ans = min(ans,visit[i].fst + visit[i].snd);
    }

    if(ans == 1e10) return cout << -1,0;
    cout << ans;
}
