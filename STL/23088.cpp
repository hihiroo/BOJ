//Aging
#include <bits/stdc++.h>
using namespace std;
#define lli unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
    cinFast();
    int n;
    cin >> n;

    int cur = 0;
    priority_queue<pair<int,pair<int,pair<int,int> > > > pq;
    for(int i=0; i<n; i++){
        int t, p, b;
        cin >> t >> p >> b;

        while(!pq.empty() && max(pq.top().snd.snd.snd, cur) < t){
            cur = max(pq.top().snd.snd.snd, cur) - pq.top().snd.fst;
            cout << -pq.top().snd.snd.fst << ' ';
            pq.pop();
        }
        pq.push(mp(-t+p,mp(-b,mp(-i-1,t))));
    }
    while(!pq.empty()){
        cur = max(pq.top().snd.snd.snd, cur) - pq.top().snd.fst;
        cout << -pq.top().snd.snd.fst << ' ';
        pq.pop();
    }
}
