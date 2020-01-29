//숨바꼭질 2
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
    fill(visit,visit+300000,300000);
    int n,k;
    cin>>n>>k;

    queue<int> q;
    q.push(n);
    visit[n] = 0;
    int fast = 10000000, cnt = 0;
    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        if(visit[vtx] > fast) break;
        if(vtx == k){
            fast = visit[vtx];
            cnt++;
        }

        if(vtx < k && visit[vtx*2] > visit[vtx]){
            visit[vtx*2] = visit[vtx]+1;
            q.push(vtx*2);
        }
        if(vtx < 300000 && visit[vtx+1] > visit[vtx]){
            visit[vtx+1] = visit[vtx]+1;
            q.push(vtx+1);
        }
        if(vtx > 0 && visit[vtx-1] > visit[vtx]){
            visit[vtx-1] = visit[vtx]+1;
            q.push(vtx-1);
        }
    }
    cout<<fast<<'\n'<<cnt;
}
