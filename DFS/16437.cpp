//양 구출 작전
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

lli arr[200000];
vector<vector<int> > p(200000);
bool visit[200000];

lli f(int vtx){
    visit[vtx] = 1;

    lli sum = arr[vtx];
    for(int i=0; i<p[vtx].size(); i++){
        int next = p[vtx][i];
        if(!visit[next]) sum += max((lli)0,f(next));
    }
    return sum;
}

int main(){
    cinFast();
    int n;
    cin >> n;

    for(int i=2; i<=n; i++){
        char a;
        int b,c;
        cin >> a >> b >> c;

        if(a == 'S') arr[i] = (lli)b;
        else arr[i] = (lli)-b;

        p[c].pb(i);
    }

    cout << f(1);
}
