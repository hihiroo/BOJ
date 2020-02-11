// 카풀 매칭
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int root[100005], N, M;
int find_root(int n){
    if(root[n] == n) return n;
    return root[n] = find_root(root[n]);
}

int full(int n){
    // n번째 보다 뒤에 있는 승객이 없으면 -1
    return root[n] = find_root(n+1);
}

int main(){
    int t;
    cin>>t;
    for(; t>0; t--){
        vector<int> human(100005);
        vector<pair<int,int> > v(100005);

        cin>>N>>M;

        for(int i=0; i<N; i++)
            scanf("%d",&human[i]);
        sort(human.begin(),human.begin()+N);

        for(int i=0; i<=N; i++) root[i] = i;

        for(int i=0; i<M; i++)//s f
            scanf("%d%d",&v[i].snd,&v[i].fst);
        sort(v.begin(),v.begin()+M);

        int ans = 0;
        for(int i=0; i<M; i++){
            int s = v[i].snd, f = v[i].fst;
            int next = lower_bound(human.begin(),human.begin()+N,s)-human.begin();
            if(next >= N) continue;

            int poss = find_root(next);
            if(poss >= N || human[poss] > f) continue;
            else{
                ans++;
                full(poss);
            }
        }
        cout<<ans<<'\n';
    }
}
