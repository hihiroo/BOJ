//어려운 소인수분해
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

bool p[2500] = {1,1};
vector<int> v;

int main(){
    for(int i=2; i<=2500; i++){
        if(p[i]) continue;
        v.pb(i);
        for(int j=2; j*i<= 2500; j++)
            p[i*j] = 1;
    }

    int n,k;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d",&k);
        int t = k;
        for(int j=0; v[j]*v[j]<=k; j++){
            if(t % v[j]) continue;
            int p = v[j];
            while(t%p == 0){
                printf("%d ",p);
                t /= p;
            }
        }
        if(t != 1)cout<<t;
        cout<<'\n';
    }
}
