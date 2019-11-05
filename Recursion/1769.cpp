// 3의 배수

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
    string a;
    int sum = 0;
    cin>>a;

    for(int i=0; i<a.size(); i++)
        sum += a[i]-'0';

    if(a.size() == 1){
        printf("0\n");
        if(sum % 3 || sum < 3) printf("NO");
        else printf("YES");
        return 0;
    }

    int cnt = 1;
    while(sum >= 10){
        int next_sum = 0;
        for(int i = sum; i>0; i/=10)
            next_sum += i % 10;
        sum = next_sum;
        cnt++;
    }

    printf("%d\n",cnt);
    if(sum % 3 || sum < 3) printf("NO");
    else printf("YES");
}


