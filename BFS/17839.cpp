//Baba is Rabbit
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

map<string, int> h;
vector<vector<string> > v(100005);

int main(){
    cinFast;

    int n;
    cin >> n;

    h["Baba"] = 0;

    int num = 1;
    for(int i=0; i<n; i++){
        string a,b,c;
        cin >> a >> b >> c;
        if(!h.count(a)) h[a] = num++;
        if(!h.count(c)) h[c] = num++;
        v[h[a]].pb(c);
    }

    vector<int> visit(100005,0);
    vector<string> ans;
    queue<string> q;
    q.push("Baba"), visit[0] = 1;

    while(!q.empty()){
        int now = h[q.front()];
        q.pop();

        for(int i=0; i<v[now].size(); i++){
            string next = v[now][i];
            int next_num = h[next];

            if(!visit[next_num]){
                visit[next_num] = 1;
                q.push(next);
                ans.pb(next);
            }
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}
