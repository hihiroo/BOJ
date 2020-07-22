//낚시왕
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int R,C,M, arr[105][105], finish[10005];

namespace fishing{
    struct shark{
        int r,c,s,d,z;

        shark(int r, int c, int s, int d, int z):
            r(r),c(c),s(s),d(d),z(z){
                if(d <= 2) s %= (R-1)*2;
                else s %= (C-1)*2;
                arr[r][c] = z;
        }

        void move(){
            int k = s;

            while(k){
                if(d == 1){
                    if(k >= r-1)
                        k -= (r-1), r = 1, d = 2;
                    else r -= k, k = 0;
                }
                else if(d == 2){
                    if(k >= R-r)
                        k -= (R-r), r = R, d = 1;
                    else r += k, k = 0;
                }
                else if(d == 3){
                    if(k >= C-c)
                        k -= (C-c), c = C, d = 4;
                    else c += k, k = 0;
                }
                else{
                    if(k >= c-1)
                        k -= (c-1), c = 1, d = 3;
                    else c -= k, k = 0;
                }
            }
            if(arr[r][c]) finish[z] = 1;
            else arr[r][c] = z;
        }
    };

    bool cmp(shark a, shark b){
        return a.z > b.z;
    }

    vector<shark> v;

    int solve(){
        sort(v.begin(),v.end(),cmp);

        int ans = 0, posi = 0;

        while(++posi <= C){
            for(int i=1; i<=R; i++){
                if(arr[i][posi]){
                    ans += arr[i][posi];
                    finish[arr[i][posi]] = 1;
                    break;
                }
            }

            memset(arr,0,sizeof(arr));

            for(int i=0; i<v.size(); i++){
                if(finish[v[i].z]) continue;
                v[i].move();
            }
        }
        return ans;
    }
}

int main(){
    using namespace fishing;

    cinFast();
    cin >> R >> C >> M;

    for(int i=0; i<M; i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        v.emplace_back(r,c,s,d,z);
    }

    cout << solve();
}
