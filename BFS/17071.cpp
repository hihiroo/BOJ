//숨바꼭질5

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int sigma(int n){
    return n * (n + 1) / 2;
}
int visit_odd[500005], visit_even[500005];

int main(){
    fill(visit_even,visit_even+500005,-1);
    fill(visit_odd,visit_odd+500005,-1);

    int n, k;
    cin >> n >> k;

    queue<pair<int,int> > q;
    q.push(mp(n,0));
    visit_even[n] = 0;

    while(!q.empty()){
        int vtx = q.front().fst;
        int cnt = q.front().snd;
        q.pop();
        
        if(cnt % 2){//odd
            if(vtx+1 <= 500000 && visit_even[vtx+1] == -1){
                visit_even[vtx+1] = visit_odd[vtx]+1;
                q.push(mp(vtx+1,cnt+1));
            }
            if(vtx-1 >= 0 && visit_even[vtx-1] == -1){
                visit_even[vtx-1] = visit_odd[vtx]+1;
                q.push(mp(vtx-1,cnt+1));
            }
            if(vtx*2 <= 500000 && visit_even[vtx*2] == -1){
                visit_even[vtx*2] = visit_odd[vtx]+1;
                q.push(mp(vtx*2,cnt+1));
            }
        }
        else{ //even
            if(vtx+1 <= 500000 && visit_odd[vtx+1] == -1){
                visit_odd[vtx + 1] = visit_even[vtx] + 1;
                q.push(mp(vtx+1,cnt+1));
            }
            if(vtx-1 >= 0 && visit_odd[vtx-1] == -1){
                visit_odd[vtx - 1] = visit_even[vtx] + 1;
                q.push(mp(vtx-1,cnt+1));
            }
            if(vtx*2 <= 500000 && visit_odd[vtx*2] == -1){
                visit_odd[vtx * 2] = visit_even[vtx] + 1;
                q.push(mp(vtx * 2,cnt+1));
            }
        }
    }
    int ans = 1000000;
    for(int i=0; k + sigma(i)<=500000; i++){
        int vtx = k + sigma(i);
        if(i % 2){//동생이 홀수초에 도착했으면
            if(i < visit_odd[vtx]) continue;// 동생보다 느리면 패스
            else ans = min(ans, i);
        }
        else{
            if(i < visit_even[vtx]) continue;
            else ans = min(ans,i);
        }
    }
    if(ans == 1000000) printf("-1");
    else printf("%d",ans);
}