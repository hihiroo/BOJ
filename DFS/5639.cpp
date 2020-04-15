//이진 검색 트리
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

vector<int> v;
pair<int,int> son[10005];
bool visit[10005];

void last(int vtx){
    if(son[vtx].fst) last(son[vtx].fst);
    if(son[vtx].snd) last(son[vtx].snd);
    cout << v[vtx] << '\n';
}

void pre(int vtx){
    visit[vtx] = 1;
    for(int i=vtx; i<v.size(); i++){
        if(!son[vtx].fst && v[i] < v[vtx])
            son[vtx].fst = i;
        if(!visit[i] && v[i] > v[vtx]){
            son[vtx].snd = i;
            visit[i] = 1;
            break;
        }
    }
    if(son[vtx].snd) pre(son[vtx].snd);
    if(son[vtx].fst) pre(son[vtx].fst);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    while(1){
        cin >> a;
        if(cin.eof()) break;
        v.pb(a);
    }

    pre(0), last(0);
}
