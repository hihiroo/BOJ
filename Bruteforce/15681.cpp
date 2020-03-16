//트리와 쿼리
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<int> > v(100005);
int ans[100005], visit[100005];

int solve(int vtx){
    visit[vtx] = 1;

    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!visit[next]) ans[vtx] += solve(next)+1;
    }

    return ans[vtx];
}

int main(){
    int n,r,q;
    cin>>n>>r>>q;
    int s,e;

    for(int i=1; i<n; i++){
        scanf("%d%d",&s,&e);
        v[s].pb(e), v[e].pb(s);
    }

    solve(r);

    while(q--){
        int a;
        scanf("%d",&a);
        printf("%d\n",ans[a]+1);
    }
}
