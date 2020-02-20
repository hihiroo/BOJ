//트리의 지름
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector<vector<pair<int,int> > > v(100005);
int ans,visit[100005];

int f(int vtx){
    visit[vtx] = 1;

    vector<int> son;
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i].fst;
        if(visit[next]) continue;
        son.pb(-v[vtx][i].snd-f(next));
    }
    if(!son.size()) return 0;

    sort(son.begin(),son.end());
    int sum = -son[0];
    if(son.size() > 1) sum += -son[1];
    ans = max(ans,sum);
    return -son[0];
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int r,s,c;
        scanf("%d",&r);
        while(1){
            scanf("%d",&s);
            if(s == -1) break;
            scanf("%d",&c);
            v[r].pb(mp(s,c));
            v[s].pb(mp(r,c));
        }
    }
    f(1);
    cout<<ans;
}
