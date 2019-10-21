//열혈강호4

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int c[2002][2002],f[2002][2002],re = -1,z;
vector<vector<int> > v(2002);

int flow(int s, int e){
    int ans=0;
    while(1){
        vector<int> par(2002,-1);
        queue<int> q;
        q.push(s);
        par[s] = s;
        while(!q.empty()){
            int vtx = q.front();
            q.pop();
            if(par[e] != -1) break;
            for(int i=0; i<v[vtx].size(); i++){
                int next = v[vtx][i];
                if(par[next] == -1 && c[vtx][next] > f[vtx][next]){
                    q.push(next);
                    par[next] = vtx;
                }
            }
        }
        if(par[e] == -1) break;
        int poss = INT_MAX;
        for(int i=e; i != s; i = par[i])
            poss = min(poss,c[par[i]][i]-f[par[i]][i]);
        for(int i=e; i!=s; i=par[i]){
            f[par[i]][i] += poss;
            f[i][par[i]] -= poss;
        }
        ans += poss;
        if(re != -1){
            re++;
            if(re == z) return ans;
        }
    }
    return ans;
}

int main(){
    int n,m,a,k;
    cin>>n>>m>>z;
    for(int i=1; i<=n; i++){//사람과 소스0 연결
        v[0].pb(i), v[i].pb(0);
        c[0][i] = 1;
    }
    for(int i=1; i<=m; i++){
        v[n+i].pb(n+m+1); //일과 싱크 연결
        v[n+m+1].pb(n+i);
        c[n+i][n+m+1] = 1;
    }

    for(int i=1; i<=n; i++){//사람과 일 연결
        cin>>k;
        for(int j=1; j<=k; j++){
            cin>>a;
            v[i].pb(n+a),v[n+a].pb(i);
            c[i][n+a] = 1;
        }
    }
    int cnt = flow(0,n+m+1);
    re = 0;
    for(int i=1; i<=n; i++)
        c[0][i]+=z;
    printf("%d",cnt + flow(0,n+m+1));
}


