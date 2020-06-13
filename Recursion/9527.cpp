//1의 개수 세기
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

lli f(lli i){
    if(i < 2) return i;

    lli k=1, len=1;
    while(k*2 <= i) len++, k*=2;

    return k/2*(len-1) + f(i-k) + (i-k+1);
}

int main(){
    lli a,b;
    cin >> a >> b;
    cout << f(b)-f(a-1);
}
