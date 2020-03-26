//최단경로
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(20001);
vector<int> chk(20001,-1);

int main(){
    int n,e,s;
    cin>>n>>e>>s;

    for(int i=0; i<e; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].pb(mp(b,c));
    }

    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,s));

    while(!pq.empty()){
        int vtx = pq.top().snd;
        int cost = -pq.top().fst;
        pq.pop();

        if(chk[vtx] != -1) continue;
        chk[vtx] = cost;

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            if(chk[next] == -1)
                pq.push(mp(-cost-v[vtx][i].snd,next));
        }
    }

    for(int i=1; i<=n; i++){
        if(chk[i] == -1) printf("INF\n");
        else printf("%d\n",chk[i]);
    }
}
