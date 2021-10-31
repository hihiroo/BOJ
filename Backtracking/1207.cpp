// 종이 자르기
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

int n, arr[15], ans[15][15], pos[5][15], start[5], finish;
vector<vector<int> > piece(5);
vector<pair<int,int> > p_sz(5);

bool chk(int y, int x, int p, int ing){
    if(ing){
        for(int i=0; i<p_sz[p].fst; i++){
            if(((arr[y+i] >> x) & piece[p][i]) != 0) return 0;
        }
    }
    for(int i=0; i<p_sz[p].fst; i++){
        arr[y+i] ^= (piece[p][i] << x);
        pos[p][y+i] ^= (piece[p][i] << x);
    }
    return 1;
}

void f(int y, int x, int cur){
    for(int p=0; p<5; p++){
        if(cur&(1<<p)) continue;
        int nx = x - start[p];

        if(y+p_sz[p].fst-1<n && nx+p_sz[p].snd-1<n && nx>=0 && chk(y,nx,p,1)){
            if((cur|(1<<p)) == (1<<5)-1){
                finish = 1;
                return;
            }
            for(int i=y, loop=1; i<n && loop; i++){
                for(int j=0; loop && j<n; j++){
                    if(arr[i] & (1<<j)) continue;
                    f(i,j,cur|(1<<p));
                    loop = 0;
                }
            }
            if(finish) return;
            chk(y,nx,p,0);
        }
    }
}

int main(){
    cinFast();
    cin >> n;

    int sum = 0;
    for(int i=0; i<5; i++){
        int y, x, tmp = 0;
        cin >> y >> x;
        p_sz[i] = {y,x};

        vector<int> k(y);
        for(int p=0; p<y; p++){
            for(int q=0; q<x; q++){
                char c;
                cin >> c;
                if(c == '#'){
                    sum++;
                    k[p] |= (1 << q);
                    if(!tmp) tmp = 1, start[i] = q;
                }
            }
        }
        piece[i] = k;
    }
    f(0,0,0);
    if(!finish || sum != n*n) return cout << "gg",0;

    for(int p=0; p<5; p++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(pos[p][i] & (1<<j)) ans[i][j] = p+1;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ans[i][j];
        cout << '\n';
    }
}
