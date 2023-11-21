#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    if(n == 0) return cout << 0, 0;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int k = (int)round((double)n*0.15);

    double sum = 0;
    for(int i=k; i<n-k; i++){
        sum += (double)v[i];
    }

    cout << (int)round(sum/(double)(n-2*k));
}