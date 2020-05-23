//Parcel
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define mp make_pair

int cnt[400005], arr[5005];
vector<pair<int,int> > v;
map<int,int> m;

int main(){
    int w,n;
    cin >> w >> n;

    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
        m[arr[i]] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            v.pb(mp(arr[i],arr[j]));
            cnt[arr[i]+arr[j]]++;
        }
    }

    for(int i=0; i<v.size(); i++){
        int sum = v[i].fst + v[i].snd;//a+b
        int need = w - sum;//c+d
        if(need < 2 || need > 400000 || !cnt[need]) continue;

        if(need == sum){//a+b == c+d일때
            if(cnt[sum] > 1)
                return cout<<"YES",0;
        }
        else{
            int exclude = 0;
            if(need-v[i].fst != v[i].fst)
                exclude += m.count(need-v[i].fst);
            if(need-v[i].snd != v[i].snd)
                exclude += m.count(need-v[i].snd);

            if(cnt[sum]-exclude)
                return cout << "YES",0;
        }
    }
    cout << "NO";
}
