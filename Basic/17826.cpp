// 나의 학점은?

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
    int arr[51];
    for(int i=0; i<50; i++) cin>>arr[i];
    sort(arr,arr+50,greater<int>());

    int H,ranking = -1;
    cin>>H;
    for(int i=0; i<50; i++)
        if(arr[i] == H){
            if(i < 5)printf("A+");
            else if(i < 15) printf("A0");
            else if(i < 30) printf("B+");
            else if(i < 35) printf("B0");
            else if(i < 45) printf("C+");
            else if(i < 48) printf("C0");
            else printf("F");
        }
}


