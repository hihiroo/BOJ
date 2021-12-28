#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define fst first
#define mp make_pair
#define snd second
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    cinFast();
    vector<int> gear(4);

    for(int i=0; i<4; i++){
        string a;
        cin >> a;

        for(int j=0; j<8; j++)
            if(a[j] == '1') gear[i] |= (1<<j);
    }

    int k;
    cin >> k;

    while(k--){
        int num, dir;
        cin >> num >> dir;
        num--;

        vector<int> rotatedir(4); // 0이면 회전x, 1이면 시계, -1이면 반시계
        rotatedir[num] = dir;

        // 오른쪽 톱니바퀴들 회전 방향 결정
        for(int i=num+1; i<4; i++){
            if((gear[i-1]&(1<<2)) == ((gear[i]&(1<<6))>>4)) break;
            rotatedir[i] = -1*rotatedir[i-1];
        }

        // 왼쪽 톱니바퀴들 회전 방향 결정
        for(int i=num-1; i>=0; i--){
            if(((gear[i+1]&(1<<6))>>4) == (gear[i]&(1<<2))) break;
            rotatedir[i] = -1*rotatedir[i+1];
        }

        // 회전
        for(int i=0; i<4; i++){
            if(rotatedir[i] == 1){ // 시계방향: 왼쪽으로 한 칸 쉬프트
                gear[i] = gear[i] << 1;
                if(gear[i] & (1<<8)){
                    gear[i] |= (1<<0);
                    gear[i] ^= (1<<8);
                }
            }
            else if(rotatedir[i] == -1){
                if(gear[i] & 1) gear[i] |= (1<<8);
                gear[i] = gear[i] >> 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<4; i++){
        if(gear[i]&(1<<0)) ans |= (1<<i);
    }
    cout << ans;
}
