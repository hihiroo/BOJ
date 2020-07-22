//보석 도둑
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n,k;
map<int,int> bag;
vector<pair<int,int> > v(300005);

int main(){
    cinFast();
    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> v[i].snd >> v[i].fst;

    sort(v.begin(),v.begin()+n);

    for(int i=0; i<k; i++){
        int a;
        cin >> a;
        bag[a]++;
    }

    lli ans = 0;
    for(int i=n-1; i>=0; i--){
        int m = v[i].snd;
        if(!bag.size() || m > bag.rbegin()->fst) continue;

        auto it = bag.lower_bound(m);
        ans += v[i].fst;
        it->snd--;
        if(it->snd == 0) bag.erase(it);
    }
    cout << ans <<'\n';
}
