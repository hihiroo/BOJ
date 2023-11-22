#include <bits/stdc++.h>
using namespace std;

int visited[1000005][11];

int main(){
    int n, k;
    cin >> n >> k;

    queue<pair<int,int> > q;
    q.push({n,0});
    visited[n][0] = 1;

    int ans = -1;
    while(!q.empty()){
        int vtx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cnt == k){
            ans = max(ans, vtx);
            continue;
        }
        
        vector<int> nb;
        while(vtx > 0){
            nb.push_back(vtx % 10);
            vtx /= 10;
        }

        
        for(int i=0; i<nb.size(); i++){
            for(int j=i+1; j<nb.size(); j++){
                if(i == j) continue;

                int newNum = 0, lv = 1, ival = nb[i], jval = nb[j], poss = 1;
                nb[i] = jval, nb[j] = ival;


                for(int idx=0; idx<nb.size(); idx++){
                    newNum += lv*nb[idx];
                    lv *= 10;
                    if(idx == nb.size()-1 && nb[idx] == 0) poss = 0;
                }

                nb[i] = ival, nb[j] = jval;
                if(!poss) continue;

                if(!visited[newNum][cnt+1]){
                    visited[newNum][cnt+1] = 1;
                    q.push({newNum,cnt+1});
                }
            }
        }
    }

    cout << ans << '\n';
}