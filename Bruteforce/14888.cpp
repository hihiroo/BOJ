#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

int n,a,b,c,d,arr[15], ans_max = -1e9, ans_min=1e9;

void f(int p, int m, int multi, int div, int num, int pre){
    if(num == n){
        ans_max = max(ans_max,pre);
        ans_min = min(ans_min,pre);
        return;
    }
    if(p) f(p-1,m,multi,div,num+1,pre+arr[num]);
    if(m) f(p,m-1,multi,div,num+1,pre-arr[num]);
    if(multi) f(p,m,multi-1,div,num+1,pre*arr[num]);
    if(div) f(p,m,multi,div-1,num+1,pre/arr[num]);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> a>> b>> c>> d;

    f(a,b,c,d,1,arr[0]);

    cout << ans_max << '\n' << ans_min;
}
