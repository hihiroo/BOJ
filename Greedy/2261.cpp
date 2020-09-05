//가장 가까운 두 점
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<int> > v(20005);

int dist(int a, int b, int c, int d){
    return (a-c)*(a-c) + (b-d)*(b-d);
}

int main(){
    cinFast();
    int n;
    cin >> n;

    for(int i=0,a,b; i<n; i++){
        cin >> a >> b;
        v[a+10000].pb(b+10000);
    }

    for(int i=0; i<=20000; i++)
        sort(v[i].begin(),v[i].end());

    int ans = 1e9;
    for(int x=0; x<=20000; x++){
        for(int j=0; j<v[x].size(); j++){
            int y = v[x][j], d = sqrt(ans);

            for(int k=max(0,x-d); k<=x; k++){
                int idx = lower_bound(v[k].begin(),v[k].end(),y)-v[k].begin();

                if(idx<v[k].size() && !(k==x && idx==j))
                    ans = min(ans,dist(x,y,k,v[k][idx]));

                if(idx+1<v[k].size() && !(k==x && idx+1==j))
                    ans = min(ans,dist(x,y,k,v[k][idx+1]));

                if(idx>0 && !(k==x && idx-1==j))
                    ans = min(ans,dist(x,y,k,v[k][idx-1]));
            }
        }
    }
    cout << ans;
}
