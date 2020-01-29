//최소비용 구하기2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back


vector<vector<pair<int,int> > > v(1005);
int visit[1005];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int s,f,cost;
        scanf("%d%d%d",&s,&f,&cost);
        v[s].pb(mp(f,cost));
    }

    int s,e;
    cin>>s>>e;
    priority_queue<pair<lli,pair<int,int > > > pq;
    pq.push(mp(0,mp(s,-1)));

    while(!pq.empty()){
        int vtx = pq.top().snd.fst;
        int pre = pq.top().snd.snd;
        lli cost = -pq.top().fst;
        pq.pop();

        if(visit[vtx]) continue;
        visit[vtx] = pre;
        if(vtx == e){
            printf("%lld\n",cost);
            break;
        }
        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i].fst;
            if(!visit[next]) pq.push(mp(-cost-v[vtx][i].snd,mp(next,vtx)));
        }
    }
    vector<int> ans;
    for(int i=e; i!=-1; i=visit[i])
        ans.pb(i);
    printf("%d\n",ans.size());
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d ",ans[i]);
}
