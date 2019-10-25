// 전깃줄 - 2 

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

bool chk[500001];
int main(){
    int n;
    vector<pair<int,int> > arr(100001);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].fst>>arr[i].snd;
        chk[arr[i].fst] = 1;
    }
    sort(arr.begin(),arr.begin()+n);

    vector<pair<int,int> > v;
    vector<int> par(500001,-1);
    v.pb(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i].snd > v.back().snd){
            par[arr[i].fst] = v.back().fst;
            v.pb(arr[i]);
        }
        else{
            int s = -1, f = v.size(), mid;
            while(s+1 < f){
                mid = (s+f)/2;
                if(v[mid].snd >= arr[i].snd)
                    f = mid;
                else s = mid;
            }
            int idx = f;
            v[idx] = arr[i];
            if(idx == 0) continue;
            par[arr[i].fst] = v[idx-1].fst;
        }
    }
    int cnt=0;
    for(int i=v.back().fst; i != -1; i=par[i]){
        cnt++;
        chk[i] = 0;
    }
    printf("%d\n",n-cnt);
    for(int i=1; i<=500000; i++)
        if(chk[i]) printf("%d\n",i);
}


