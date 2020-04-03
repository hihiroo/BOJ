//N과 M(1)
//15649번
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int visit[10], n, m;

void btk(int vtx, vector<int> ans){
    visit[vtx] = 1;
    ans.pb(vtx);

    if(ans.size() == m){
        for(int i=0; i<ans.size(); i++)
            printf("%d ",ans[i]);

        printf("\n");
        visit[vtx] = 0;
        return;
    }

    for(int i=1; i<=n; i++){
        if(!visit[i]) btk(i,ans);
    }

    visit[vtx] = 0;
}

int main(){
    cin >> n >> m;

    vector<int> tmp;
    for(int i=1; i<=n; i++){
        btk(i,tmp);
    }
}