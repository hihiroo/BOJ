//벽 부수고 이동하기 4
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int n,m,arr[1000][1000],un,group[1000000];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool safe(int a, int b){
    return a>=0 && a<n && b>=0 && b<m;
}
int dfs(int y, int x){
    group[un]++;
    arr[y][x] = -un;
    for(int i=0; i<4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(safe(ny,nx) && !arr[ny][nx])
            dfs(ny,nx);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&arr[i][j]);

    for(int i=0; i<n; i++){//0인 것들 그룹화
        for(int j=0; j<m; j++){
            if(!arr[i][j]){
                un ++;
                dfs(i,j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                priority_queue<int> q;
                for(int k=0; k<4; k++){
                    int ny = i + dir[k][0];
                    int nx = j + dir[k][1];
                    if(safe(ny,nx) && arr[ny][nx]<0)
                        q.push(-arr[ny][nx]);
                }
                int gn=0;
                while(!q.empty()){
                    if(q.top() == gn){
                        q.pop();
                        continue;
                    }
                    gn = q.top();
                    arr[i][j] += group[gn];
                    q.pop();
                }
            }
            printf("%d",max(0,arr[i][j]%10));
        }
        printf("\n");
    }
}
