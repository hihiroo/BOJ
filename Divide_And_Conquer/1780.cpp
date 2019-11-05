// 종이의 개수

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

int arr[3000][3000],a,b,c,n;


void f(int y, int x, int size){
    if(size == 1){
        if(arr[y][x] == -1) a++;
        else if(arr[y][x] == 0) b++;
        else c++;
        return;
    }

    for(int i=y; i<size+y; i++){
        for(int j=x; j<size+x; j++){
            if(arr[y][x] != arr[i][j]){
                for(int p=0; p<3; p++){
                    for(int q=0; q<3; q++)
                        f(y+(size/3)*p,x+(size/3)*q,size/3);
                }
                return;
            }
        }
    }

    if(arr[y][x] == -1) a++;
    else if(arr[y][x] == 0) b++;
    else c++;
    return;
}


int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];

    f(1,1,n);
    printf("%d\n%d\n%d",a,b,c);
}


