#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v(10005);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, end;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.begin()+n);

    int pos = 0, idx = 0, ans = 0;
    priority_queue<int> pq;
    cin >> end >> pos;


    while(pos < end){
        while(idx < n && pos >= v[idx].first){ // 현재 위치까지의 주유소 pq에 추가
            pq.push(v[idx].second);
            idx++;        
        }
        if(pq.empty()) return cout << -1, 0;
        pos += pq.top();
        pq.pop();
        ans++;
    }
    cout << ans << '\n';
}