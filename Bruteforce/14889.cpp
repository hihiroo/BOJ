//스타트와 링크
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int ans = 1e9, n, arr[25][25];

void f(int idx, int cur, int r, int b){
    if(idx == n){
        ans = min(abs(r-b),ans);
        return;
    }

    int nr = 0, nb = 0, cntR =0, cntB=0;
    for(int i=0; i<idx; i++){
        if(cur & (1<<i)) cntR++, nr += arr[i][idx]+arr[idx][i];
        else cntB++, nb += arr[i][idx]+arr[idx][i];
    }

    if(cntR < n/2) f(idx+1,cur|(1<<idx),r+nr,b);
    if(cntB < n/2) f(idx+1,cur,r,b+nb);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    f(1,0,0,0);
    cout << ans;
}
