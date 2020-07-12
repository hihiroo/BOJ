//게리맨더링2
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, arr[25][25], line[25][25];

int zone5(int x, int y, int d1, int d2){
    memset(line,0,sizeof(line));

    for(int i=0; i<=d1; i++) line[x+i][y-i] = 5, line[x+d2+i][y+d2-i] = 5;
    for(int i=1; i<=d2; i++) line[x+i][y+i] = 5, line[x+d1+i][y-d1+i] = 5;

    int cnt = 0;
    for(int r=1; r<=n; r++){
        int s=100,f=0;

        for(int c=1; c<=n; c++)
            if(line[r][c]) s = min(s,c), f = max(f,c);

        if(s == 100) continue;
        for(int c=s; c<=f; c++) cnt += arr[r][c], line[r][c] = 5;
    }

    return cnt;
}

int zone1(int x, int y, int d1){
    int cnt = 0;
    for(int r=1; r<x+d1; r++)
        for(int c=1; c<=y; c++)
           if(!line[r][c]) cnt += arr[r][c];
    return cnt;
}

int zone2(int x, int y, int d2){
    int cnt = 0;
    for(int r=1; r<=x+d2; r++)
        for(int c=y+1; c<=n; c++)
            if(!line[r][c]) cnt += arr[r][c];
    return cnt;
}

int zone3(int x, int y, int d1, int d2){
    int cnt = 0;
    for(int r=x+d1; r<=n; r++)
        for(int c=1; c<y-d1+d2; c++)
            if(!line[r][c]) cnt += arr[r][c];
    return cnt;
}

int zone4(int x, int y, int d1, int d2){
    int cnt = 0;
    for(int r=x+d2+1; r<=n; r++)
        for(int c=y-d1+d2; c<=n; c++)
            if(!line[r][c]) cnt += arr[r][c];
    return cnt;
}

int solve(int x, int y, int d1,int d2){
    int arr[5];
    arr[4] = zone5(x,y,d1,d2); // 무조선 zone5 먼저 호출
    arr[0] = zone1(x,y,d1);
    arr[1] = zone2(x,y,d2);
    arr[2] = zone3(x,y,d1,d2);
    arr[3] = zone4(x,y,d1,d2);

    sort(arr,arr+5);
    return arr[4]-arr[0];
}

int main(){
    cinFast();

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    int ans = 1e9;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int d1=1; d1<j; d1++)
                for(int d2=1; i+d1+d2<=n && j+d2<=n; d2++)
                    ans = min(ans,solve(i,j,d1,d2));
    cout << ans;
}
