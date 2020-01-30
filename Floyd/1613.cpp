//역사
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


int arr[405][405];

int main(){
    fill(&arr[0][0],&arr[404][404],100000);

    int n,k;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int s,f;
        scanf("%d%d",&s,&f);
        arr[s][f] = 1;
    }

    for(int t=1; t<=n; t++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                arr[i][j] = min(arr[i][j],arr[i][t]+arr[t][j]);

    int m,s,f;
    cin>>m;
    for(int i=0; i<m; i++){
        scanf("%d%d",&s,&f);
        if(arr[s][f] < arr[f][s]) cout<<-1<<'\n';
        else if(arr[s][f] == arr[f][s]) cout<<0<<'\n';
        else cout<<1<<'\n';
    }

}
