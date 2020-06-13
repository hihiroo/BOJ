// 세 용액
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

lli arr[5005], pick[3];
int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        scanf("%lld",&arr[i]);

    sort(arr,arr+n);

    lli ans = 1e10;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            lli sum = arr[i] + arr[j];

            int idx = lower_bound(arr+j+1,arr+n,-sum)-arr;

            if(idx != n && abs(sum+arr[idx]) < ans){
                ans = abs(sum+arr[idx]);
                pick[0] = arr[i];
                pick[1] = arr[j];
                pick[2] = arr[idx];
            }

            if(idx-1 > j && abs(sum+arr[idx-1])<ans){
                ans = abs(sum+arr[idx-1]);
                pick[0] = arr[i];
                pick[1] = arr[j];
                pick[2] = arr[idx-1];
            }
        }
    }

    for(int i=0; i<3; i++) printf("%lld ",pick[i]);
}
