//K번째 괄호 문자열

#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli dp[55][30][30], n, k;

lli f(int l, int open, int close){
    if(l == n) return open == close;
    lli &ret = dp[l][open][close];
    if(ret != -1) return ret;

    ret = f(l+1,open+1,close);
    if(open > close) ret += f(l+1,open,close+1);

    return ret;
}

int main(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    k++;

    queue<char> q;
    int l = 1, open = 0, close = 0;
    while(l <= n){
        if(f(l,open+1,close) >= k){
            q.push('(');
            open++;
        }
        else if(open>close && f(l,open,close+1)+f(l,open+1,close) >= k){
            k -= f(l,open+1,close);
            q.push(')');
            close++;
        }
        else return cout << -1,0;
        l++;
    }

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
}
