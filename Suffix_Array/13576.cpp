#include <bits/stdc++.h>
using namespace std;

int pos[1000005], sa[1000005], lcp[1000005], d, len;
// sa는 접미사가 시작하는 위치(접미사 번호)(사전 순 랭커가 몇 번째 접미사인지)
// pos는 i번째 접미사의 그룹 번호(i번째 접미사의 사전순 랭킹)
// 즉, sa완성 후 pos는 i번째 접미사가 몇번째 인덱스에 있는지
string a;

bool cmp(int x, int y){
    if(pos[x] != pos[y]) return pos[x] < pos[y]; // 빠른 그룹 먼저
    if(x+d < len && y+d < len) return pos[x+d] < pos[y+d];
    // 현재 같은 그룹에 속하면 앞에서부터 d개가 같은 것이므로
    // 앞의 d개를 지운 접미사의 그룹 번호를 비교함으로써 d*2개 비교
    return x > y; // 다 같으면 길이가 짧은게 먼저 오도록
}

void constructSA(){
    for(int i=0; i<len; i++){
        pos[i] = a[i];
        sa[i] = i;
    }
    for(d=1; ;d*=2){
        sort(sa, sa+len, cmp); // sa를 그룹 번호 순으로 정렬
        vector<int> tmp(len);

        for(int i=1; i<len; i++){ // 그룹 번호 다시 매김
            tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
        }
        for(int i=0; i<len; i++) pos[sa[i]] = tmp[i];
        if(tmp[len-1] == len-1) break;
    }
}

void constructLCP(){
    // i번째 접미사와 i+1번째 접미사는 앞에 한글자 빼고 똑같으므로
    // i번째 접미사와 앞에서 k개 같은 접미사를 a라고 하면 i+1번째 접미사는 a+1번째와 k-1개 같음
    // 따라서 sa배열에서 i+1번째 바로 밑의 접미사는 최소 k-1개까지는 같음
    for(int i=0,k=0; i<len; i++, k=max(k-1,0)){ // i는 시작 위치
        if(pos[i] == len-1) continue;
        // j는 사전 순으로 바로 밑에 있는 접미사
        for(int j=sa[pos[i]+1]; a[i+k]==a[j+k]; k++);
        lcp[i] = k;
    }
}

int main(){
    cin >> a;
    len = a.size();

    constructSA();
    constructLCP();

    long long ans = ((long long)len*(long long)(len+1))/2;
    for(int i=0; i<len; i++) ans -= lcp[i];
    cout << ans << '\n';
}