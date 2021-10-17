//이모티콘
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int chk[2005][1005];

int main(){
    int n;
    cin >> n;

    memset(chk,-1,sizeof(chk));

    queue<pair<int,int> > q;
    q.push({1,0});
    chk[1][0] = 0;

    while(!q.empty()){
        int vtx = q.front().fst;
        int clip = q.front().snd;
        q.pop();

        if(vtx == n) return cout << chk[vtx][clip],0;

        if(vtx-1 && chk[vtx-1][clip] == -1){
            chk[vtx-1][clip] = chk[vtx][clip]+1;
            q.push({vtx-1,clip});
        }
        if(vtx < n && chk[vtx][vtx] == -1){
            chk[vtx][vtx] = chk[vtx][clip]+1;
            q.push({vtx,vtx});
        }
        if(clip && vtx+clip < 2*n && chk[vtx+clip][clip] == -1){
            chk[vtx+clip][clip] = chk[vtx][clip]+1;
            q.push({vtx+clip, clip});
        }
    }
}
