// 좌표 정렬하기 2

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    int n,a,b,c;
    vector<pair<int,pair<int,pair<int,int> > > > v(10001);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b>>c;
        v[i].first = -a;
        v[i].snd.fst = b;
        v[i].snd.snd.fst = c;
        v[i].snd.snd.snd = i;
    }
    sort(v.begin()+1,v.begin()+n+1);
    printf("%d",v[1].snd.snd.snd);
}


