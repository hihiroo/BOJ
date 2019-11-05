// 쿼드트리

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
int arr[64][64],n;

void f(int x, int y, int sz){
    bool chk = 1;

    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(arr[i+x][j+y] != arr[x][y]){
                chk = 0;
                break;
            }
        }
        if(!chk) break;
    }

    if(!chk){
        printf("(");
        f(x,y,sz/2);
        f(x,y+sz/2,sz/2);
        f(x+sz/2,y,sz/2);
        f(x+sz/2,y+sz/2,sz/2);
        printf(")");
    }
    else printf("%d",arr[x][y]);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d",&arr[i][j]);
    f(0,0,n);
}



