//공주님의 정원
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int main(){
    vector <pair<int,int> > v(100000);
    int n,a,b,c,d;
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int m_sum[13]={0,};
    for(int i=1; i<13; i++) m_sum[i] = m_sum[i-1]+m[i];

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf(" %d %d %d %d",&a,&b,&c,&d);
        v[i].first = m_sum[a-1]+b;
        v[i].second = -(m_sum[c-1]+d-1);
    }
    sort(v.begin(),v.begin()+n);

    int s_point = m[1]+m[2]+1, f_point=0;
    int finish = m_sum[11], cnt = 0;
    bool chk = false;
    for(int i=0; i<n; i++){
        if(f_point >= -v[i].second) continue;

        if(v[i].first <= s_point){
            if(!chk){
                cnt++;
                chk = true;
            }
            f_point = max(f_point,-v[i].second);
        }
        else if(f_point != 0){
            s_point = f_point+1;
            f_point = 0;
            chk = false;
            if(v[i].first <= s_point){
                if(!chk){
                    cnt++;
                    chk = true;
                }
                f_point = max(f_point,-v[i].second);
            }
        }
        if(f_point >= finish)
            return !printf("%d",cnt);
    }
    printf("0");
}
