//녹색 옷 입은 애가 젤다지?
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int n,arr[125][125];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool safe(int y, int x){
    return y>=0 && y<n && x>=0 && x<n;
}
bool visit[125][125];
int main(){
    int t = 1;
    while(1){
        cin>>n;
        if(!n) return 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        fill(&visit[0][0],&visit[124][125],0);
        priority_queue<pair<int,pair<int,int> > >q;
        q.push(mp(-arr[0][0],mp(0,0)));
        while(!q.empty()){
            int cost = -q.top().first;
            int y = q.top().second.first;
            int x = q.top().second.second;
            q.pop();
            if(visit[y][x]) continue;
            visit[y][x] = 1;
            if(y == n-1 && x == n-1){
                printf("Problem %d: %d\n",t++,cost);
                break;
            }
            for(int i=0; i<4; i++){
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                if(safe(ny,nx) && !visit[ny][nx])
                    q.push(mp(-cost-arr[ny][nx],mp(ny,nx)));
            }
        }
    }
}
