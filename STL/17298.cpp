// 오큰수
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    cinFast();
    int n, a;
    cin >> n;

    priority_queue<pair<int,int> > s;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        cin >> a;
        while(!s.empty() && -s.top().fst < a){
            ans[s.top().snd] = a;
            s.pop();
        }
        s.push({-a,i});
    }
    while(!s.empty()){
        ans[s.top().snd] = -1;
        s.pop();
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";
}
