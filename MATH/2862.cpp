//수학 게임 (정수론, 규칙찾기)

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

lli n, fibo[75] = {1,2,3,5};
int main(){

    cin>>n;

    for(int i=3; i<75; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    while(1){
        int k = upper_bound(fibo,fibo+75,n) - fibo -1;
        if(fibo[k] == n) return !printf("%lld",n);
        else n -= fibo[k];
    }
}
