//최장 공통 부분 문자열
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define lli long long
#define fst first
#define snd second
#define coutFix(a) cout<<fixed;cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string a,b,s;
int pos[200005], sa[200005], d, len, lcp[200005];
// sa는 접미사 번호(그룹번호가 작은 순으로 정렬됨)
// pos는 i번째 접미사의 그룹 번호(사전순으로 작을수록 그룹번호도 작음)
// 즉, sa완성 후 pos는 i번째 접미사가 몇번째 인덱스에 있는지

bool cmp(int i, int j){ // i번째 접미사가 j번째 접미사보다 그룹 번호가 작도록
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    if(i+d < len && j+d < len) return pos[i+d] < pos[j+d];
    // 현재 같은 그룹에 속하면 앞에서부터 d개가 같은 것이므로
    // 앞의 d개를 지운 접미사의 그룹 번호를 비교함으로써 d*2개 비교
    return i > j; // 다 같으면 접미사 길이가 찗은 순으로
}

void construct(){
    len = s.size();

    for(int i=0; i<len; i++){
        pos[i] = s[i]; // i번째 접미사의 맨 앞 글자로 그룹 번호를 매김
        sa[i] = i; // sa에 접미사 번호 넣음. 나중에 정렬할거
    }

    for(d=1; ; d*=2){
        sort(sa,sa+len,cmp);

        //앞에서 d*2개씩 같아지도록 그룹 번호를 다시 매김
        vector<int> tmp(len);
        for(int i=1; i<len; i++)
            tmp[i] = tmp[i-1] + cmp(sa[i-1],sa[i]);

        for(int i=0; i<len; i++) pos[sa[i]] = tmp[i];

        if(tmp[len-1] == len-1) break; // 그룹이 접미사 개수만큼 생기면 종료
    }
}

void buildLCP(){
    // i번째 접미사와 i+1번째 접미사는 앞에 한글자 빼고 똑같으므로
    // i번째 접미사와 앞에서 k개 같은 접미사를 a라고 하면 i+1번째 접미사는 a+1번째와 k-1개 같음
    // 따라서 sa배열에서 i+1번째 바로 밑의 접미사는 최소 k-1개까지는 같음
    for(int i=0,k=0; i<len; i++,k=max(k-1,0)){ //i번째 접미사
        if(pos[i] == len-1) continue; // 사전순으로 마지막이면 패스

        // j는 sa배열에서 i 바로 밑에 있는 접미사
        for(int j=sa[pos[i]+1]; s[i+k]==s[j+k]; k++);
        lcp[i] = k; //i번째 접미사와 j번째 접미사는 앞에서 k개 같다.
    }
}

int main(){
    cin >> a >> b;
    s = a+ '#' + b;

    construct();
    buildLCP();

    int ans = 0, idx;
    for(int i=0; i<len-1; i++){
        if(sa[i] < a.size() && sa[i+1] > a.size()){
            int k = a.size()-sa[i];
            if(ans < min(k,lcp[sa[i]])){
                ans = min(k,lcp[sa[i]]);
                idx = sa[i];
            }
        }
        else if(sa[i+1] < a.size() && sa[i] > a.size()){
            int k = a.size()-sa[i+1];
            if(ans < min(k,lcp[sa[i]])){
                ans = min(k,lcp[sa[i]]);
                idx = sa[i+1];
            }
        }
    }

    cout << ans << '\n';
    cout << s.substr(idx,ans);
}
