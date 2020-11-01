//LCS 4
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int A[100005], B[100005], idx[100005];

int main(){
    cinFast();
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
        idx[A[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
        B[i] = idx[B[i]];
    }

    vector<int> par(100005,-1), v;
    v.pb(B[0]);

    for(int i=1; i<n; i++){
        if(B[i] > v.back()){
            par[B[i]] = v.back(); // 부모가 더 작음
            v.pb(B[i]);
        }
        else{
            int p = lower_bound(v.begin(),v.end(),B[i])-v.begin();
            v[p] = B[i]; 
            // 벡터는 크기순으로 정렬되어있음
            // 항상 p-1번째는 B[i]보다 작거나 같으므로 나중에 등장한 값이랑 연결하는게 이득
            if(p == 0) continue;
            par[B[i]] = v[p-1];
        }
    }

    int ans = 0;
    for(int i=v.back(); i!=-1; i=par[i]) ans++;

    cout << ans;
}
