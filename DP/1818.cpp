//책정리
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<pair<int,int> > v;
vector<int> par(200005,-1);

int main(){

    int n, a;
    cin >> n >> a;
    v.pb(mp(a,0));

    for(int i=1; i<n; i++){
        scanf("%d",&a);
        if(a > v.back().fst){
            par[i] = v.back().snd;
            v.pb(mp(a,i));
        }
        else{
            int s = -1, f = v.size()-1;
            while(s+1 < f){
                int mid = (s+f)/2;
                if(v[mid].fst >= a) f = mid;
                else s = mid;
            }
            v[f] = mp(a,i);
            if(f == 0) continue;
            par[i] = v[f-1].snd;
        }
    }

    int cnt = 0;
    for(int i=v.back().snd; i!=-1; i=par[i])
        cnt++;
    cout << n-cnt;
}
