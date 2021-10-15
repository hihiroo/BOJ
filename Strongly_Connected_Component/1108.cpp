// 검색 엔진
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

vector<vector<int> > v(2505), scc(2505);
stack<int> s;
vector<int> chk(2505), finish(2505);
int cnt = 0, scc_cnt;

int dfs(int vtx){
    chk[vtx] = ++cnt;
    s.push(vtx);

    int par = chk[vtx];
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];

        if(!chk[next]) par = min(par, dfs(next));
        else if(!finish[next])par = min(par, chk[next]);
    }

    if(par == chk[vtx]){
        scc_cnt++;

        while(!s.empty()){
            int q = s.top();
            s.pop();
            scc[scc_cnt].pb(q);
            finish[q] = scc_cnt;
            if(q == vtx) break;
        }
    }
    return par;
}

map<string, int> m;

int main(){
    cinFast();
    int n, k, address = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> k;
        if(!m[a]) m[a] = ++address;

        for(int j=0; j<k; j++){
            cin >> b;
            if(!m[b]) m[b] = ++address;
            v[m[b]].pb(m[a]);
        }
    }

    string c;
    cin >> c;

    if(!m[c]) m[c] = ++address;
    int target = m[c];

    for(int i=1; i<=address; i++)
        if(!chk[i]) dfs(i);

    vector<int> in(scc_cnt+1);
    vector<lli> score(address+1,1);

    for(int i=1; i<=address; i++){
        int start_scc = finish[i];

        for(int j=0; j<v[i].size(); j++){
            int end_scc = finish[v[i][j]];

            if(start_scc == end_scc) continue;
            in[end_scc]++;
        }
    }

    queue<int> q;
    for(int k=1; k<=scc_cnt; k++){
        if(in[k]) continue;
        q.push(k);

        while(!q.empty()){
            int vtx = q.front(); // scc 번호
            q.pop();

            for(int i=0; i<scc[vtx].size(); i++){
                int node = scc[vtx][i]; // vtx scc 안의 노드

                for(int j=0; j<v[node].size(); j++){
                    int end_node = v[node][j]; // node->end_node
                    int end_scc = finish[end_node];

                    if(vtx == end_scc) continue;

                    score[end_node] += score[node];
                    if(--in[end_scc] == 0) q.push(end_scc);
                }
            }
        }
    }

    cout << score[target];
}
