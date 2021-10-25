//과제
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

bool hwday[1005];

int main(){
    cinFast();
    int n;
    cin >> n;

    vector<pair<int,int> > v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].snd >> v[i].fst;

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=v.size()-1; i>=0; i--){
        for(int j=v[i].snd; j>=1; j--){
            if(!hwday[j]){
                ans += v[i].fst;
                hwday[j] = 1;
                break;
            }
        }
    }

    cout << ans;
}
