//0 만들기
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fst first
#define snd second
#define lli long long
#define pb push_back
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);

int n;

void f(int cnt, string a){
    if(cnt == n+1){
        int l = 0, r = 0, op = 0, sum = 0;
        for(int i=0; i<a.size(); i++){
            if(i%2){
                if(a[i] == ' '){
                    if(op) r *= 10;
                    else l *= 10;
                }
                else if(op){
                    if(op == 1) sum += l+r;
                    else sum += l-r;
                    l = 0, r = 0;
                }
                if(a[i] != ' '){
                    if(a[i] == '+') op = 1;
                    else op = -1;
                }
            }
            else{
                if(op) r += a[i]-'0';
                else l += a[i]-'0';
            }
        }
        if(op == -1) sum += l-r;
        else sum += l+r;

        if(sum == 0) cout << a << '\n';
        return;
    }
    char nxt = cnt + '0';

    f(cnt+1, a+" "+nxt);
    f(cnt+1, a+"+"+nxt);
    f(cnt+1, a+"-"+nxt);
}

int main(){
    cinFast();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        f(2, "1");
        cout << '\n';
    }
}
