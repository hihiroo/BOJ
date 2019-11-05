//색종이 만들기

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

int arr[200][200],w,b,n;


void f(int y, int x, int size){
    if(size == 1){
        if(arr[y][x] == 0) w++;
        else b++;
        return;
    }

    for(int i=y; i<size+y; i++){
        for(int j=x; j<size+x; j++){
            if(arr[y][x] != arr[i][j]){
                f(y,x,size/2);
                f(y+size/2,x,size/2);
                f(y,x+size/2,size/2);
                f(y+size/2,x+size/2,size/2);
                return;
            }
        }
    }

    if(arr[y][x] == 1) b++;
    else w++;
    return;
}


int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];

    f(1,1,n);
    printf("%d\n%d",w,b);
}


