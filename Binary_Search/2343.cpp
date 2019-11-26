// 기타 레슨

#include <bits/stdc++.h>
using namespace std;

int m,n,arr[100005];

bool up(int lv){
    int cnt = 1, sum = 0;
    for(int i=1; i<=n; i++){
        if(arr[i] > lv) return 0;
        if(sum + arr[i] > lv){
            cnt++;
            sum = 0;
        }
        sum += arr[i];
        
    }
    return m >= cnt;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);

    int s = 0, f = 1000000005; //블루레이의 크기 범위
    while(s+1 < f){
        int mid = (s+f)/2;
        if(up(mid)) f = mid;
        else s = mid;
    }
   cout<<f;
}