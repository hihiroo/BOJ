//개미굴
#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<pair<string, int>, int> m;
vector<vector<pair<string,int> > > v(100005);

void f(int vtx, int depth){
    for(int i=0; i<v[vtx].size(); i++){
        for(int k=0; k<depth*2; k++)
            cout << "-";

        cout << v[vtx][i].fst << '\n';
        f(v[vtx][i].snd,depth+1);
    }
}

int main(){
    cinFast();

    int n;
    cin >> n;

    int cnt = 1, k;
    while(n--){
        cin >> k;

        string a;
        int pre = 0;

        for(int i=1; i<=k; i++){
            cin >> a;

            if(!m.count(mp(a,pre))){
                m[mp(a,pre)] = cnt++;
                v[pre].pb(mp(a,m[mp(a,pre)]));
            }
            
            pre = m[mp(a,pre)];
        }
    }

    for(int i=0; i<cnt; i++)
        sort(v[i].begin(),v[i].end());

    f(0,0);
}
