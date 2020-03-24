//길의 개수
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli mod = 1000003;
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

bool arr[50][50];

int main(){
    int n,s,e,t;
    cin>>n>>s>>e>>t;

    s--, e--;
    for(int i=0; i<5*n; i++){
        if(i%5) arr[i][i-1] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int k;
            scanf("%1d",&k);
            if(k) arr[i*5][j*5+k-1] = 1;
        }
    }

    matrix adj(5*n);
    for(int i=0; i<5*n; i++){
        for(int j=0; j<5*n; j++)
            adj[i].pb(arr[i][j]);
    }

    adj = fast_pow(adj,t);
    cout<<adj[s*5][e*5];
}
