//단어 암기
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define lli long long
using namespace std;


vector<int> v(10005);

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        for(int j=0; j<a.size(); j++)
            v[i] |= 1<<(a[j]-'a');
    }

    int ban = 0;
    for(int i=0; i<m; i++){
        int q;
        char c;

        scanf(" %d %c",&q,&c);
        ban |= 1<<(c-'a');
        if(q == 2) ban -= (1<<(c-'a'));

        int ans = n;
        for(int j=0; j<n; j++)
            if(ban & v[j]) ans--;

        printf("%d\n",ans);
    }
}
