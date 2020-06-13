//작업
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int cost[10005], in[10005], dist[10005];
vector<vector<int> > v(10005);

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        scanf("%d%d",&cost[i],&in[i]);
        for(int j=0; j<in[i]; j++){
            int a;
            scanf("%d",&a);
            v[a].pb(i);
        }
    }

    for(int i=1; i<=n; i++){
        if(in[i] || dist[i]) continue;
        queue<int> q;
        dist[i] = cost[i];
        q.push(i);

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            for(int j=0; j<v[vtx].size(); j++){
                int adj = v[vtx][j];
                if(--in[adj] == 0) q.push(adj);
                dist[adj] = max(dist[adj],dist[vtx]+cost[adj]);
            }
        }
    }
    sort(dist+1,dist+n+1);
    cout << dist[n];
}
