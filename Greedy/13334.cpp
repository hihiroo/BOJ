//철로
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<lli> v;
map<lli,lli> de,in;
//de[i]는 i가 몇 번째로 작은 수인지
//in[i]은 i번째로 작은 수가 뭔지
pair<lli,lli> arr[100005];

bool cmp(pair<lli,lli> a, pair<lli,lli> b){
    if(a.snd == b.snd) return a.fst < b.fst;
    return a.snd < b.snd;
}

int main(){
    cinFast();
    lli n;
    cin >> n;

    for(lli i=0,a,b; i<n; i++){
        cin >> a >> b;
        a += 100000001, b += 100000001;

        v.pb(a), v.pb(b);
        if(a > b) swap(a,b);
        arr[i] = mp(a,b);
    }
    sort(arr,arr+n,cmp);

    /*좌표압축*/
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    de[0] = 0, in[0] = 0;
    for(lli i=0; i<v.size(); i++)
        de[v[i]] = i+1, in[i+1] = v[i];

    lli s = 0, f = 0, d, ans = 0, k = 0;
    vector<lli> cnt(200005);
    cin >> d;

    for(lli i=0; i<n; i++){
        lli a = arr[i].fst, b = arr[i].snd;
        if(a < s) continue;
        //길이가 d를 넘으면 s 당기기
        f = b, k++, cnt[de[a]]++;
        while(f-s > d){
            k -= cnt[de[s]];
            s = in[de[s]+1];
        }
        ans = max(ans,k);
    }
    cout << ans;
}
