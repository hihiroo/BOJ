//본대 산책2
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli mod = 1e9+7;
#define matrix vector<vector<lli> >

matrix gop(matrix a, matrix b){
    matrix ret(a.size());

    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++){
            ret[i].pb(0);
            for(int k=0; k<a.size(); k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix a, int b){
    if(b == 1) return a;
    if(b%2) return gop(fast_pow(a,b-1),a);
    matrix tmp = fast_pow(a,b/2);
    return gop(tmp,tmp);
}

int con[8][8] = {
{0,1,1,0,0,0,0,0},
{1,0,1,1,0,0,0,0},
{1,1,0,1,1,0,0,0},
{0,1,1,0,1,1,0,0},
{0,0,1,1,0,1,1,0},
{0,0,0,1,1,0,0,1},
{0,0,0,0,1,0,0,1},
{0,0,0,0,0,1,1,0}};
//정보과학관 = 0, 전산관 = 1, 미래관 = 2,
// 신양관 = 3, 한경직기념관 = 4, 진리관 = 5,
// 형남공학관 = 6, 학생회관 = 7

int main(){
    int t;
    cin>>t;

    matrix adj(8);
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            adj[i].pb(con[i][j]);

    adj = fast_pow(adj,t);
    cout<<adj[0][0];
}
