//단어 수학
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second


map<char,int> m;
int cnt[11];

int main(){
    int n, appear = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        for(int j=0; j<a.size(); j++){
            if(m.find(a[j]) == m.end())
                m[a[j]] = appear++;
            cnt[m[a[j]]] += pow(10,a.size()-j-1);
        }
    }
    sort(cnt,cnt+appear,greater<int>());
    lli ans = 0, num = 9;
    for(int i=0; i<appear; i++){
        ans += cnt[i]*num;
        num--;
    }
    cout<<ans;
}
