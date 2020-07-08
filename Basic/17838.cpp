//커맨드
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        char arr[10005];
        scanf("%s",arr);

        bool poss = true;

        if(strlen(arr) != 7) poss = false;
        else{
            if(arr[0] == arr[2]) poss = false;
            else{
                char A = arr[0], B = arr[2];
                char a[8] = {A,A,B,B,A,B,B};
                if(strcmp(arr,a) != 0) poss = false;
            }
        }

        if(poss) printf("1\n");
        else printf("0\n");
    }
}
