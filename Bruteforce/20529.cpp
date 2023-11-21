#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> v(n), filtered;
        for(int i=0; i<n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int cnt = 1;
        filtered.push_back(v[0]);

        for(int i=1; i<n; i++){
            if(v[i] == v[i-1]) cnt++;
            else cnt = 1;
            if(cnt <= 3) filtered.push_back(v[i]);    
        }

        int ans = 1e9;
        for(int i=0; i<filtered.size(); i++){
            for(int j=i+1; j<filtered.size(); j++){
                int ijgap = 0;
                for(int idx=0; idx<4; idx++)
                    if(filtered[i][idx] != filtered[j][idx]) ijgap++;

                for(int k=j+1; k<filtered.size(); k++){
                    int gap = ijgap;
                    for(int idx=0; idx<4; idx++){
                        if(filtered[i][idx] != filtered[k][idx]) gap++;
                        if(filtered[j][idx] != filtered[k][idx]) gap++;
                    }
                    ans = min(ans, gap);
                }
            }
        }
        cout << ans << '\n';
    }
}