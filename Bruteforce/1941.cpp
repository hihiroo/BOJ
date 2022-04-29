// 소문난 칠공주
#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

int cnt1bit(int k){
    int cnt = 0;
    while(k){
        if(k&1) cnt++;
        k = k >> 1;
    }
    return cnt;
}

int arr[5], dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            char a;
            cin >> a;
            if(a == 'S') arr[i] |= (1<<j);
        }
    }

    vector<vector<int> > res;
    for(int r1=0; r1<(1<<5); r1++){
        int remain = 7 - cnt1bit(r1), cntS1 = cnt1bit(r1&arr[0]);

        for(int r2=0; r2<(1<<5); r2++){
            int remain2 = remain - cnt1bit(r2), cntS2 = cntS1 + cnt1bit(r2&arr[1]);

            for(int r3=0; r3<(1<<5); r3++){
                int remain3 = remain2 - cnt1bit(r3), cntS3 = cntS2 + cnt1bit(r3&arr[2]);

                for(int r4=0; r4<(1<<5); r4++){
                    int remain4 = remain3 - cnt1bit(r4), cntS4 = cntS3 + cnt1bit(r4&arr[3]);

                    for(int r5=0; r5<(1<<5); r5++){
                        int remain5 = remain4 - cnt1bit(r5), cntS5 = cntS4 + cnt1bit(r5&arr[4]);
                        if(remain5 == 0 && cntS5 >= 4){
                            vector<int> tmp = {r1, r2, r3, r4, r5};
                            res.push_back(tmp);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<res.size(); i++){
        vector<int> chk(5);
        queue<pair<int,int> > q;
        int cnt = 0;

        for(int y=0; y<5; y++){
            for(int x=0; x<5; x++){
                if((chk[y]&(1<<x)) || !(res[i][y]&(1<<x))) continue;
                cnt++;
                q.push({y,x});
                chk[y] |= (1<<x);

                while(!q.empty()){
                    int yy = q.front().fst;
                    int xx = q.front().snd;
                    q.pop();

                    for(int j=0; j<4; j++){
                        int ny = yy + dir[j][0], nx = xx + dir[j][1];
                        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                        if(!(chk[ny]&(1<<nx)) && (res[i][ny]&(1<<nx))){
                            q.push({ny,nx});
                            chk[ny] |= (1<<nx);
                        }
                    }
                }
            }
        }
        if(cnt == 1) ans++;
    }
    cout << ans;
}
