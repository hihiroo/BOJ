//행렬 제곱

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int N, mod = 1000;
typedef vector<vector<int> > matrix;

matrix gop(matrix a, matrix b){
    matrix ret(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ret[i].pb(0);
            for(int k=0; k<N; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix a, lli b){
    if(b == 1) return a;
    if(b%2) return gop(a,fast_pow(a,b-1));
    matrix temp = fast_pow(a,b/2);
    return gop(temp,temp);
}

int main(){
    lli B;
    cin>>N>>B;
    matrix M(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int t;
            cin>>t;
            M[i].pb(t%mod);
        }
    }
    M = fast_pow(M,B);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<M[i][j]<<" ";
        cout<<'\n';
    }
}

