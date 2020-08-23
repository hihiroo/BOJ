//Suffix Array
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
int d, sa[500005], gn[500005], len, lcp[500005];

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

void buildLcp(){
    //gn[i]는 i번째 접미사가 사전순으로 몇 번째인지,
    //sa[i]는 사전순으로 i번째 접미사가 몇 번인지

    //사전순으로 인접한 x와 y 접미사가 앞에서부터 k개 일치하면
    //x+1,y+1도 인접해있고 최소 k-1개 일치한다.
    //O(n)
    for(int i=0, k=0; i<len; i++,k=max(k-1,0)){
        //사전순으로 마지막이면 패스
        if(gn[i] == len-1) continue;
        //사전순으로 바래 아래 접미사와 얼마나 일치하는지 구함
        for(int j=sa[gn[i]+1]; a[i+k] == a[j+k]; k++);

        lcp[gn[i]] = k;
    }
}

int main(){
    cin >> a;
    construct();
    buildLcp();

    for(int i=0; i<len; i++)
        cout << sa[i]+1 << " ";

    cout << "\nx ";

    for(int i=0; i<len-1; i++)
        cout << lcp[i] << " ";
}
