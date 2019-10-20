// 제곱수의 합

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

int main(){
    int n, ans = 4;
    cin>>n;

    for(int a=1; a<=500; a++){
        int a2 = a*a;
        if(a2 == n) ans = min(ans,1);
        for(int b=a; b<=500; b++){
            int b2 = b*b;
            if(a2+b2 == n) ans = min(ans,2);
            for(int c=b; c<=500; c++){
                int c2 = c*c;
                if(a2+b2+c2 == n) ans = min(ans,3);
            }
        }
    }
    cout<<ans;
}
