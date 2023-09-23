#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > candy(30005);
int dp[3005], gcnt;

struct Union{
    vector<int> root;
    Union(int n): root(n+1){
        for(int i=1; i<=n; i++)
            root[i] = i, candy[i].second = 1;
    }
    int find(int n){
        if(root[n] == n) return n;
        return root[n] = find(root[n]);
    }
    void merge(int a, int b){
        int r1 = find(a), r2 = find(b);
        root[r1] = r2;
        candy[r2].first += candy[r1].first;
        candy[r2].second += candy[r1].second;
        candy[r1] = {0,0};
        gcnt--;
    }
    bool isconnected(int a, int b){
        return find(a) == find(b);
    }
};

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first) return true;
    else if(a.first != b.first) return false;
    else if(a.second < b.second) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    Union group(n);
    gcnt = n;

    for(int i=1; i<=n; i++) cin >> candy[i].first;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(group.isconnected(a,b)) continue;
        group.merge(a,b);
    }
    sort(candy.begin(), candy.end(), cmp);

    for(int i=0; i<gcnt; i++){
        for(int j=k-1; j>=1; j--){
            if(candy[i].second <= j)
                dp[j] = max(dp[j], dp[j-candy[i].second] + candy[i].first);
        }
    }

    cout << dp[k-1] << '\n';
}