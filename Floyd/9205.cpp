//맥주 마시면서 걸어가기
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int can[105][105];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<int,int> > v;
        for(int i=0; i<n+2; i++){
            int y,x;
            scanf("%d%d",&y,&x);
            v.pb(mp(y,x));
        }

        fill(&can[0][0],&can[n+3][n+3],0);

        for(int i=0; i<n+2; i++){
            for(int j=i+1; j<n+2; j++){
                if(abs(v[i].fst-v[j].fst) + abs(v[i].snd-v[j].snd) <= 1000)
                    can[i][j] = 1, can[j][i] = 1;
            }
        }

        for(int k=0; k<n+2; k++)
            for(int i=0; i<n+2; i++)
                for(int j=0; j<n+2; j++)
                    can[i][j] |= (can[i][k]&can[k][j]);

        if(can[0][n+1]) cout << "happy\n";
        else cout << "sad\n";
    }
}
