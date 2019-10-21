//체스로 도미노를 타자

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

int n,k,arr[1005][3],dp[3005][1<<3][1005],d;

int f(int idx, int cur, int domino){
    if(domino == 0) return 0;
    if(idx >= 3*n) return d-3000000;
    int &ret = dp[idx][cur][domino];
    if(dp[idx][cur][domino] != d) return ret;


    ret = f(idx+1,cur>>1,domino);//그냥 지나감
    if(cur & 1) return ret;

    int row = idx/3, col = idx%3;
    if(row+1 < n){
        int next = cur | (1<<3);
        ret = max(ret,arr[row][col]+arr[row+1][col]
                  +f(idx+1,next>>1,domino-1));
    }
    if(col != 2 && !(cur & 2)){
        int next = cur | 2;
        ret = max(ret,arr[row][col]+arr[row][col+1]
                  +f(idx+2,next>>2,domino-1));
    }
    return ret;
}

int main(){
    d = -2*pow(10,9);
    for(int i=0; i<3005; i++)
        for(int j=0; j<(1<<3); j++)
            for(int p=0; p<1005; p++)
                dp[i][j][p] = d;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            scanf("%d",&arr[i][j]);
    printf("%d",f(0,0,k));
}


