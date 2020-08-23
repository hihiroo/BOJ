//접미사 배열2
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string a;
int d, sa[100005], gn[100005], len;

bool cmp(int i, int j){
    if(gn[i] != gn[j]) return gn[i] < gn[j];
    //그룹이 같으면 뒤에 d칸도 비교
    if(i+d < len && j+d < len) return gn[i+d] < gn[j+d];
    //비교할게 없으면 짧은게 먼저
    return i > j;
}

void construct(){
    len = a.size();

    for(int i=0; i<len; i++){
        sa[i] = i;
        gn[i] = a[i];
    }//맨 첫글자로 그룹 번호 매김

    for(d=1; ; d*=2){
        //그룹 번호가 작은순으로 정렬
        sort(sa,sa+len,cmp);

        vector<int> temp(len);

        for(int i=1; i<len; i++)
            temp[i] = temp[i-1] + cmp(sa[i-1],sa[i]);

        for(int i=0; i<len; i++) gn[sa[i]] = temp[i];
        if(temp[len-1] == len-1) break;
    }
}

int main(){
    cin >> a;
    construct();

    for(int i=0; i<len; i++)
        cout << sa[i] << '\n';
}
