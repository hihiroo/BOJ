//스도쿠
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int row[10][10], col[10][10], squre[10][10];
int arr[10][10], poss;

void f(int r, int c){
    if(poss) return;
    if(r == 9) poss = 1;
    if(c == 9) f(r+1,0);
    if(arr[r][c]) f(r,c+1);
    if(r == 9 || c == 9 || arr[r][c]) return;

    int k = (r/3)*3 + c/3;

    for(int j=1; j<=9; j++){
        if(row[r][j] || col[c][j] || squre[k][j])
            continue;

        row[r][j] = 1, col[c][j] = 1, squre[k][j] = 1;
        arr[r][c] = j;

        f(r,c+1);
        if(poss) return;

        row[r][j] = 0, col[c][j] = 0, squre[k][j] = 0;
        arr[r][c] = 0;
    }
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%1d",&arr[i][j]);
            if(!arr[i][j]) continue;

            row[i][arr[i][j]] = 1;
            col[j][arr[i][j]] = 1;
            int k = (i/3)*3 + j/3;
            squre[k][arr[i][j]] = 1;
        }
    }


    f(0,0);

    for(int i=0; i<9; i++,printf("\n"))
        for(int j=0; j<9; j++) printf("%d",arr[i][j]);

}
