//민준이와 마산 그리고 건우
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


vector<vector<pair<int,int> > > v(5005);
int visit[5005];
bool meet[5005];

int main(){
    int n,E,P;
    cin>>n>>E>>P;
    for(int i=0; i<E; i++){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }

    priority_queue<pair<int,pair<int,bool> > > pq;
    pq.push(mp(0,mp(1,0)));

    int dist = 100000000;
    while(!pq.empty()){
        int cost = -pq.top().fst;
        int vtx = pq.top().snd.fst;
        bool pickup = pq.top().snd.snd;
        pq.pop();

        if(visit[vtx] || meet[vtx]) continue;
        visit[vtx] = cost, meet[vtx] = pickup;
        if(cost > dist) break;
        if(vtx == P) pickup = true;
        if(vtx == n){
            if(pickup) return cout<<"SAVE HIM",0;
            else continue;
        }

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            int ncost = v[vtx][i].snd + cost;
            if(!visit[next] || (pickup && !meet[next]))
                pq.push(mp(-ncost,mp(next,pickup)));
        }
    }
    return cout<<"GOOD BYE",0;
}
