// 두 배열의 합
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<lli, lli> is;
lli sumA[1005], sumB[1005];

int main(){
    lli t;
    cin >> t;

    int n,m;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> sumA[i];
        sumA[i] += sumA[i-1];
    }

    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> sumB[i];
        sumB[i] += sumB[i-1];
    }

    for(int i=0; i<m; i++)
        for(int j=i+1; j<=m; j++)
            is[sumB[j]-sumB[i]]++;

    lli ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=n; j++){
            lli take = t - (sumA[j]-sumA[i]);
            ans += is[take];
        }
    }
    cout << ans;
}
