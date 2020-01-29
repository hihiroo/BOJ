//로봇 프로젝트
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

vector<int> v;

int main(){
    while(1){
        int x;
        cin>>x;
        if(cin.eof()) return 0;
        x *= 10000000;
        v.clear();

        int n, l;
        cin>>n;
        for(int i=0; i<n; i++){
            scanf("%d",&l);
            v.pb(l);
        }
        sort(v.begin(),v.end());

        bool finish = false;
        for(int i=0; i<v.size(); i++){
            int target = x - v[i];
            int idx = lower_bound(v.begin()+i+1,v.end(),target)-v.begin();
            if(idx == v.size() || v[idx] != target)
                continue;
            printf("yes %d %d\n",v[i],target);
            finish = true;
            break;
        }
        if(!finish) printf("danger\n");
    }
}

