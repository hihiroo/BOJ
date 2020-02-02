//Numbers
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

typedef  vector<vector<int> > matrix;
int mod = 1000;

matrix gop(matrix a, matrix b){
    matrix ret(2);
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ret[i].pb(0);
            for(int k=0; k<2; k++){
                ret[i][j] += a[i][k]*b[k][j];
                ret[i][j] = ((ret[i][j]%mod)+mod)%mod;
            }
        }
    }
    return ret;
}

matrix fast_pow(matrix a, int b){
    if(b == 1) return a;
    if(b % 2) return gop(a,fast_pow(a,b-1));
    matrix tmp = fast_pow(a,b/2);
    return gop(tmp,tmp);
}

int main(){
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case #"<<i<<": ";

        int n;
        cin>>n;
        matrix ans(2);
        ans[0].pb(6), ans[0].pb(-4);
        ans[1].pb(1), ans[1].pb(0);
        ans = fast_pow(ans,n-1);
        int sum = (ans[0][0]*6 + ans[0][1]*2-1)%mod;
        if(sum < 100) cout<<"0";
        if(sum < 10) cout<<"0";
        cout<<sum<<'\n';
    }
}
