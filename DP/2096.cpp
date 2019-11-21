//내려가기

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

bool safe(int x){
    return x>=0 && x<3;
}
int main(){
    int n,a[3],dp1[2][3],dp2[2][3];
    int dir[3] = {-1,0,1};
    cin>>n>>a[0]>>a[1]>>a[2];
    for(int i=0; i<3; i++){
        dp1[0][i] = a[i];
        dp2[0][i] = a[i];
    }
    for(int i=1; i<n; i++){
        cin>>a[0]>>a[1]>>a[2];
        for(int j=0; j<3; j++){
            dp1[1][j] = 0, dp2[1][j] = 2000000000;
            for(int k=0; k<3; k++){
                if(safe(j+dir[k])){
                    dp1[1][j] = max(dp1[1][j],dp1[0][j+dir[k]]+a[j]);
                    dp2[1][j] = min(dp2[1][j],dp2[0][j+dir[k]]+a[j]);
                }
            }
        }
        for(int j=0; j<3; j++){
            dp1[0][j] = dp1[1][j];
            dp2[0][j] = dp2[1][j];
        }
    }
    int ans1 = 0, ans2 = 2000000000;
    for(int i=0; i<3; i++){
        ans1 = max(dp1[0][i],ans1);
        ans2 = min(dp2[0][i],ans2);
    }
    printf("%d %d",ans1,ans2);
}

