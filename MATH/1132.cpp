//합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

lli cnt[30];
bool cant0[30];
vector<lli> v;

int main(){
    int n;
    cin>>n;

    string a;
    for(int i=0; i<n; i++){
        cin>>a;
        lli lv = 1;
        for(int j=a.size()-1; j>=0; j--){
            cnt[a[j]-'A'] += lv;
            lv *= 10;
        }
        cant0[a[0]-'A'] = 1;
    }

    lli ans = 0;
    for(int i=0; i<=9; i++) v.pb(i);

    do{
        int k = 0, poss = true;
        lli sum = 0;
        for(int i=0; i<=26; i++){
            if(!cnt[i]) continue;
            if(v[k] == 0 && cant0[i]){
                poss = false;
                break;
            }
            sum += v[k++]*cnt[i];
        }
        if(poss) ans = max(ans,sum);
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans;
}
