// 반도체 설계

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int n,arr[40001];
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> par(40001,-1),v;
    v.pb(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i] > v.back()){
            par[arr[i]] = v.back();
            v.pb(arr[i]);
        }
        else{
            int p = lower_bound(v.begin(),v.begin()+v.size(),arr[i])-v.begin();
            v[p] = arr[i];
            if(p == 0) continue;
            par[arr[i]] = v[p-1];
        }
    }
    vector<int> ans;
    for(int i=v.back(); i != -1; i=par[i])
        ans.pb(i);
    printf("%d\n",ans.size());
}



