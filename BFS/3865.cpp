//학회원
#include <bits/stdc++.h>
using namespace std;
#define lli long long
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

int main(){
    cinFast();
    int t;
    while(1){
        cin >> t;
        if(t == 0) break;

        vector<vector<int> > v(t*11+1);
        map<string, int> m;
        int cnt = 0, ans = 0;

        for(int i=0; i<t; i++){
            string a;
            cin >> a;

            string tmp = "";
            for(int j=0, gr=-1; j<a.size(); j++){
                if('a' <= a[j] && a[j] <= 'z') tmp += a[j];
                else{
                    if(!m[tmp]) m[tmp] = ++cnt;
                    if(gr == -1) gr = m[tmp];
                    else v[gr].pb(m[tmp]);
                    tmp = "";
                }
            }
        }

        queue<int> q;
        vector<bool> chk(t*11+1);
        q.push(1), chk[1] = 1;

        while(!q.empty()){
            int vtx = q.front();
            q.pop();

            for(int i=0; i<v[vtx].size(); i++){
                int nxt = v[vtx][i];
                if(chk[nxt]) continue;

                chk[nxt] = 1;
                if(v[nxt].size()) q.push(nxt);
                else ans++;
            }
        }
        cout << ans << '\n';
    }
}
