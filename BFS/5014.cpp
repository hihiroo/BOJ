//스타트링크
#include <bits/stdc++.h>
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int visit[1000005];

int main(){
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    //1~f까지의 층, 현재 s층, g층으로 이동

    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        if(vtx == g) return cout << visit[vtx]-1,0;

        if(vtx+u <= f && !visit[vtx+u]){
            visit[vtx+u] = visit[vtx]+1;
            q.push(vtx+u);
        }
        if(vtx-d >= 1 && !visit[vtx-d]){
            visit[vtx-d] = visit[vtx]+1;
            q.push(vtx-d);
        }
    }
    return cout << "use the stairs",0;
}
