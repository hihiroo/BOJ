//IOIOI
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

int main(){
    int n,l;
    cin>>n>>l;

    string a;
    cin>>a;
    int ans = 0, cnt = 0;
    for(int i=0; i<a.size()-2; i++){
        if(a[i] == 'I'){
            if(a[i+1] == 'O' && a[i+2] == 'I'){
                cnt++;
                if(cnt >= n) ans++;
            }
            else cnt = 0;
        }
    }
    cout<<ans;
}