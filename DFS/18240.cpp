// 이진 탐색 트리 복원하기
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

vector<vector<int> > lv(300005);
int ans[300005],cnt;

void inorder(int depth, int vtx, int j){
    int left=0, right=0, left_j, right_j;
    for(int i=j*2; i<lv[depth+1].size(); i++){
        int next = lv[depth+1][i];
        if(!ans[next]){
            if(!left){
                left = next;
                left_j = i;
            }
            else{
                right = next;
                right_j = i;
            }
        }
        if(left && right) break;
    }
    if(left) inorder(depth+1,left, left_j);
    ans[vtx] = ++cnt;
    if(right) inorder(depth+1,right,right_j);
}

int main(){
    int n;
    cin>>n;
    lv[0].pb(0);

    bool poss = true;
    for(int i=1; i<n; i++){
        int k;
        scanf("%d",&k);
        if(!poss) continue;

        lv[k].pb(i);
        if(2*lv[k-1].size() < lv[k].size())
            poss = false;
    }
    if(!poss) return cout<<"-1",0;
    inorder(0,0,0);
    for(int i=0; i<n; i++) printf("%d ",ans[i]);
}
