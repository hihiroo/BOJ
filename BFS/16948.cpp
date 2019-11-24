// 데스 나이트

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int n, dir[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
bool safe(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

bool visit[205][205];

int main(){
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    priority_queue<pair<int, pair<int, int> > >q;
    q.push(mp(0, mp(r1, c1)));
    while (!q.empty()){
        int cnt = -q.top().fst;
        int y = q.top().snd.fst;
        int x = q.top().snd.snd;
        q.pop();

        if (visit[y][x]) continue;
        visit[y][x] = 1;

        if (y == r2 && x == c2)
            return !printf("%d", cnt);

        for (int i = 0; i < 6; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (safe(ny, nx) && !visit[ny][nx])
                q.push(mp(-cnt - 1, mp(ny, nx)));
        }
    }
    printf("-1");
}