//숨바꼭질3
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

int visit[300001];
int main(){
    memset(visit,-1,sizeof(visit));
    int n,k;
    cin>>n>>k;

    priority_queue<pair<int,int> > q;
    q.push(mp(0,n));
    while(!q.empty()){
        int vtx = q.top().snd;
        int cnt = -q.top().fst;
        q.pop();

        if(visit[vtx] != -1) continue;
        visit[vtx] = cnt;
        if(vtx == k) return cout<<visit[vtx],0;

        if(abs(k-vtx*2) < abs(k-vtx) && visit[vtx*2] == -1)
            q.push(mp(-visit[vtx],vtx*2));
        if(vtx < 300000 && visit[vtx+1] == -1)
            q.push(mp(-visit[vtx]-1,vtx+1));
        if(vtx > 0 && visit[vtx-1] == -1)
            q.push(mp(-visit[vtx]-1,vtx-1));
    }
}
