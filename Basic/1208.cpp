//부분수열의 합 2

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

int n,s;
lli cnt[4000001][2], delta[4000001][2];

int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        delta[abs(k)][k<0]++;

        for(int j=0; j<=2500000; j++){
            delta[abs(j+k)][(j+k)<0] += cnt[j][0];
            if(j) delta[abs(-j+k)][(-j+k)<0] += cnt[j][1];
        }

        for(int j=0; j<=2500000; j++){
            cnt[j][0] += delta[j][0];
            cnt[j][1] += delta[j][1];
            delta[j][0] = 0, delta[j][1] = 0;
        }
    }
    cout<<cnt[abs(s)][s<0];
}
