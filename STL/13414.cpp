//수강신청
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;

map<string, int> m;
vector<string> v(500005);

int main(){
    int k,l;
    scanf("%d%d",&k,&l);

    for(int i=0; i<l; i++){
        char num[9];
        scanf("%s",num);
        v[i] = num;
        m[num] = i;
    }

    int cnt = 0;
    for(int i=0; i<l; i++){
        if(cnt == k) break;
        if(m[v[i]] == i){
            printf("%s\n",v[i].c_str());
            cnt++;
        }
    }
}
