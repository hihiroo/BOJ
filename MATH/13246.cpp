//행렬 제곱의 합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int mod = 1000, n;

typedef vector<vector<int> > matrix;

matrix gop(matrix a, matrix b){
    matrix ret(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret[i].pb(0);
            for(int k=0; k<n; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix m, lli k){
    if(k == 1) return m;
    if(k % 2) return gop(m,fast_pow(m,k-1));
    else{
        matrix temp = fast_pow(m,k/2);
        return gop(temp,temp);
    }
}

matrix sum(lli k, matrix m){
    if(k == 1) return m;
    matrix ret, a;
    if(k % 2){
        ret = sum(k-1,m);
        a = fast_pow(m,k);
    }
    else{
        ret = sum(k/2,m);
        a = gop(ret,fast_pow(m,k/2));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret[i][j] += a[i][j];
            ret[i][j] %= mod;
        }
    }
    return ret;
}

int main(){
    lli b;
    cin>>n>>b;
    matrix v(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            v[i].pb(k);
        }
    }
    matrix ans = sum(b,v);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}

