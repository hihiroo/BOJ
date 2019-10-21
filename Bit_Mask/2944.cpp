//수박 던지기 게임

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

lli dist[1<<20],n,h,arr[25][25],sum[25],chk[1<<20];

int main(){
    cin>>n>>h;
    for(lli i=0; i<n; i++){
        for(lli j=0; j<n; j++){
            scanf("%1lld",&arr[i][j]);
            if(arr[i][j] == 1) sum[i]++;
        }
    }
    lli cur = 0;
    for(lli i=0; i<n; i++)
        if(arr[0][i]) cur |= (1<<i);

    lli time = 2, cnt = sum[0];
    if(h == 1) return !printf("%lld",cnt);

    while(1){
        lli next = 0;
        for(lli i=0; i<n; i++){
            if(cur & (1<<i)){
                for(lli j=0; j<n; j++){
                    if(arr[i][j]){
                        if(next & (1<<j))
                            next -= (1<<j);
                        else next |= (1<<j);
                        cnt++;
                    }
                }
            }
            else cnt += sum[i]*2;
        }
        if(chk[cur]){
            int gap = time - chk[cur];
            cnt += (h-time)/gap*(cnt-dist[cur]);
            time += (h-time)/gap*gap;
        }
        if(time == h) return !printf("%lld",cnt);
        chk[cur] = time++;
        dist[cur] = cnt;
        cur = next;
    }
}


