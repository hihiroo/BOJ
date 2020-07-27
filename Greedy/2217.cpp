// 로프
#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n,greater<int>());

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, arr[i]*(i+1));
    }
    cout << ans;
}
