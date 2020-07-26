//불 끄기
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> status(12);
int ans = 1e9;

void xoR(int &cur, int idx){
    if(idx < 0 || idx == 10) return;
    if(cur&(1<<idx)) cur -= (1<<idx);
    else cur |= (1<<idx);
}

void turn(int &cur, int &next, int idx){
    xoR(cur,idx);
    xoR(cur,idx-1);
    xoR(cur,idx+1);
    xoR(next,idx);
}

int f(int row, int pre, int now){
    if(row == 10) return pre ? 1e8 : 0;

    int cnt = 0, next = status[row+1];
    for(int i=0; i<10; i++){
        if(pre&(1<<i)){ //켜져있으면
            cnt++;
            turn(now,next,i);
        }
    }
    return f(row+1,now,next)+cnt;
}

void solve(int idx, int cur, int next, int cnt){
    if(idx == 10){
        ans = min(ans,cnt+f(1,cur,next));
        return;
    }
    solve(idx+1,cur,next,cnt);

    //스위치 누르기
    turn(cur,next,idx);
    solve(idx+1,cur,next,cnt+1);
}

int main(){
    cinFast();
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char a;
            cin >> a;
            if(a == 'O') status[i] |= (1<<j);
        }
    }
    solve(0,status[0],status[1],0);
    cout << (ans >= 1e8 ? -1 : ans);
}
