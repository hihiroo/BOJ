//상어의 저녁식사
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

struct Shark{
    int size, speed, intel;
}shark[55];

vector<vector<int> > v(105);
int f[105][105], c[105][105];

int cmp(Shark a, Shark b){
    if(a.size == b.size && a.intel == b.intel && a.speed == b.speed)
        return 0;
    if(a.size >= b.size && a.speed >= b.speed && a.intel >= b.intel)
        return 1;
    else return -1;
}

int flow(int s, int e){
    int ans = 0;
    while(1){
        vector<int> par(105,-1);
        queue<int> q;
        q.push(s);
        par[s] = s;
        while(!q.empty() && par[e] == -1){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(par[next] == -1 && c[vtx][next] > f[vtx][next]){
                    par[next] = vtx;
                    q.push(next);
                }
            }
        }
        if(par[e] == -1) break;
        int poss = 1000000;
        for(int i=e; i != s; i=par[i])
            poss = min(poss,c[par[i]][i]-f[par[i]][i]);

        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }
        ans += poss;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d%d%d",&shark[i].size, &shark[i].speed, &shark[i].intel);
        v[0].pb(i), v[i].pb(0);
        v[i+n].pb(2*n+1), v[2*n+1].pb(i+n);
        c[0][i] = 2, c[i+n][2*n+1] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            int ret = cmp(shark[i],shark[j]);
            if((!ret && i < j) || ret == 1){
                v[i].pb(j+n), c[i][j+n] = 1;
                v[j+n].pb(i);
            }
        }
    }
    cout<<n-flow(0,2*n+1);
}
