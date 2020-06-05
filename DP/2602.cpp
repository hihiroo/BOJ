//돌다리 건너기
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int dp[105][105][2];
string a,b,magic;

int f(int idx, int k, int angel){
    if(k == -1) return 1;
    if(idx < 0) return 0;
    int &ret = dp[idx][k][angel];
    if(ret != -1) return ret;

    ret = 0;

    if(angel){
        if(b[idx] == magic[k])
            ret = f(idx-1,k-1,0);
        ret += f(idx-1,k,1);
    }
    else{
        if(a[idx] == magic[k]) ret = f(idx-1,k-1,1);
        ret += f(idx-1,k,0);
    }
    
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));

    cin >> magic >> a >> b;

    int ans = f(a.size()-1,magic.size()-1,1);
    ans += f(a.size()-1,magic.size()-1,0);

    cout << ans;
}
