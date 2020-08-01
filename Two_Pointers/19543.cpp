#include <bits/stdc++.h>
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define cinFast() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<int> > v(30);

int main(){
    cinFast();
    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0; i<k; i++){
        string a;
        cin >> a;
        for(int j=0; j<a.size(); j++)
            if(a[j] == 'U') v[i].pb(j);
    }

    string str;
    cin >> str;

    reverse(str.begin(),str.end());


    int s = 0, e = m-1, boss = str[0]-'A'; // [s,e]
    for(int i=0; i<v[boss].size(); i++){
        if(v[boss][i] < m-1) s = v[boss][i]+1;
    }

    lli ans = (lli)(e-s+1);

    for(int i=1; i<str.size(); i++){
        int num = str[i] - 'A';

        //s찾기
        int ns = lower_bound(v[num].begin(),v[num].end(), s)-v[num].begin();
        if(ns == v[num].size() || v[num][ns] > e) break; // 모두 s보다 작고 e보다 크면 범위 안으로 올라갈 수 없음
        if(ns == 0) s = 0; // 처음 U가 s,e 사이면 전범위
        else s = v[num][ns-1]+1;

        //e찾기
        int ne = upper_bound(v[num].begin(),v[num].end(), e)-v[num].begin();
        e = v[num][ne-1];

        ans += (lli)(e-s+1);
    }
    cout << ans;
}
