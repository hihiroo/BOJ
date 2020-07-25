//카드 게임
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int card[4000005], rt[2005];

int f(int t){
    for(int i=t/2000; i<=2000; i++){
        if(rt[i] == 0) continue;
        for(int j=max(i*2000,t+1); ; j++){
            if(card[j]){
                card[j]--, rt[i]--;
                return j;
            }
        }
    }
}

int main(){
    cinFast();

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        card[a]++, rt[a/2000]++;
    }

    for(int i=0; i<k; i++){
        int t;
        cin >> t;
        cout << f(t) << '\n';
    }
}