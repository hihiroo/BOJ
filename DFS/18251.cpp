//내 생각에 A번인 단순 DFS 문제가 이 대회에서 E번이 되어버린 건에 관하여
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

pair<int,lli> arr[300000];
int cnt = 0, n, depth[300000];

void f(int vtx, int d){
    if(vtx > n) return;

    f(vtx*2,d+1);

    arr[vtx].fst = ++cnt;
    depth[cnt] = d;

    f(vtx*2+1,d+1);
}

int main(){
    cinFast();
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i].snd;
    f(1,1);

    sort(arr+1,arr+1+n);

    lli ans = -1e18;
    for(int i=1; i<=18; i++){
        for(int j=i+1; j<=18; j++){
            lli sum = -1e18;

            for(int k=1; k<=n; k++){
                if(depth[arr[k].fst] < i || depth[arr[k].fst] > j) continue;
                sum = max(arr[k].snd, sum+arr[k].snd);
                ans = max(ans,sum);
            }
        }
    }

    cout << ans;
}
