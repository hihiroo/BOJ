// 제곱 ㄴㄴ

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

lli p[100005], k,v[100005];

bool up(lli lv){
    lli cnt = lv;
    for(lli i=1; i*i<=lv; i++){
        if(p[i] == -2) continue;
        cnt += lv/(i*i) * p[i]; //뫼비우스 함수
        //합집합 법칙
    }

    return cnt>=k;
}

int main(){
    //뫼비우스 함수를 에라토스테네스의 채 응용해서 구하기
    //제곱수로 안 나뉘면 0, 제곱수가 홀수개이면 -1, 짝수개면 1
    for(lli i=2; i<=100000; i++){
        if(p[i] != 0) continue;
        v[i] = 1, p[i] = -1; //소수면 -1
        for(lli j=2; j*i <= 100000; j++){
            if(j%i == 0) p[i*j] = -2;
            if(p[i*j] == -2) continue;
            else if(p[i*j] == 0) p[i*j] = -1;
            else p[i*j] *= -1;
        }
    }
    cin>>k;

    lli s = 0, f = INT_MAX;
    while(s+1 < f){
        lli mid = (s+f)/2;
        if(up(mid)) f = mid;
        else s = mid;
    }
    cout<<f;
}
