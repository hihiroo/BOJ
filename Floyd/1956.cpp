//운동
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

lli arr[405][405];
#define INF 1000000000000
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++)
            arr[i][j] = INF;


    for(int i=0; i<e; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        arr[a][b] = c;
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    lli ans = INF;
    for(int i=1; i<=v; i++)
        ans = min(ans,arr[i][i]);
    if(ans == INF) return cout<<-1,0;
    else return cout<<ans,0;
}
