//반복 부분문자열
#include <bits/stdc++.h>
#define lli long long
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define coutFixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int l, sa[200005], pos[200005], d, lcp[200005];
//sa[i]는 사전순으로 i번째인 접미사
//pos[i]는 i 접미사의 사전순 번호
string a;

bool cmp(int i, int j){
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    if(i+d < l && j+d < l) return pos[i+d] < pos[j+d];
    //다 같으면 접미사 길이가 짧은게 먼저 오도록
    return i > j;
}

void buildSA(){
    for(int i=0; i<l; i++){
        sa[i] = i;
        pos[i] = a[i];
    }

    for(d=1; ; d*=2){
        sort(sa,sa+l,cmp);

        vector<int> tmp(l);

        for(int i=1; i<l; i++)
            tmp[i] = tmp[i-1] + cmp(sa[i-1],sa[i]);

        for(int i=0; i<l; i++) pos[sa[i]] = tmp[i];

        if(tmp[l-1] == l-1) break;
    }
}

void buildLCP(){
    for(int i=0, k=0; i<l; i++, k = max(k-1,0)){
        if(pos[i] == l-1) continue;

        for(int j=sa[pos[i]+1]; a[i+k] == a[j+k]; k++);
        lcp[i] = k;
    }
}

int main(){
    cin >> l >> a;

    buildSA();
    buildLCP();

    int ans = 0;
    for(int i=0; i<l; i++) ans = max(ans,lcp[i]);

    cout << ans;
}
