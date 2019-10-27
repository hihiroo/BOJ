// 피리부는 사나이

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lli long long int

int ans;
struct DS{
  vector<int> par;
  DS(int n) : par(n){
    for(int i=0; i<n; i++)
      par[i] = i;
  }
  int root_find(int u){ // 루트 찾기
    if(u == par[u]) return u;
    return par[u] = root_find(par[u]);
  }
  int mg(int v1, int v2){
    v1 = root_find(v1); v2 = root_find(v2);
    if(v1 == v2) return ans++; // 싸이클 생기면 ++
    return par[v1] = v2;
  }
};

int main(){
    int n,m;
    char dir;
    cin>>n>>m;
    DS A(n*m+1);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cur= i*m + j + 1;
            cin>>dir;

            if(dir == 'D' && i+1<n)
                A.mg(cur,cur+m);

            else if(dir == 'L' && j>0)
                A.mg(cur,cur-1);

            else if(dir == 'U' && i>0)
                A.mg(cur,cur-m);

            else if(j<m-1)//'R'
                A.mg(cur,cur+1);

        }
    }
    printf("%d",ans);
}


