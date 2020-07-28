//루머
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<int> > v(200005);
int visit[200005], in[200005];

int main(){
    memset(visit,-1,sizeof(visit));

    int n;
    cinFast();
    cin >> n;

    for(int i=1; i<=n; i++){
        int a;
        while(1){
            cin >> a;
            if(a == 0) break;
            v[i].pb(a);
        }
    }

    int m;
    cin >> m;

    queue<int> q;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        q.push(a);
        visit[a] = 0;
    }

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(visit[next] != -1) continue;
            if(++in[next]>=(v[next].size()+1)/2){
                visit[next] = visit[vtx]+1;
                q.push(next);
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout << visit[i] << " ";
}
