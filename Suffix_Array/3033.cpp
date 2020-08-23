//가장 긴 문자열
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string a;
int d, len, sa[200005], pos[200005], lcp[200005];

bool cmp(int i, int j){
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    if(i+d < len && j+d < len) return pos[i+d] < pos[j+d];
    return i > j;
}

void constructSA(){
    for(int i=0; i<len; i++){
        sa[i] = i;
        pos[i] = a[i];
    }

    for(d=1; ; d*=2){
        sort(sa,sa+len,cmp);

        vector<int> tmp(len);
        for(int i=1; i<len; i++)
            tmp[i] = tmp[i-1] + cmp(sa[i-1],sa[i]);

        for(int i=0; i<len; i++)
            pos[sa[i]] = tmp[i];

        if(tmp[len-1] == len-1) break;
    }
}

void constructLCP(){
    for(int i=0, k=0; i<len; i++, k=max(k-1,0)){
        if(pos[i] == len-1) continue;

        for(int j=sa[pos[i]+1]; a[i+k] == a[j+k]; k++);
        lcp[i] = k;
    }
}

int main(){
    cin >> len >> a;
    constructSA();
    constructLCP();

    int ans = 0;
    for(int i=0; i<len; i++)
        ans = max(ans,lcp[i]);
    cout << ans;
}
