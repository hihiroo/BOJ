//음주코딩

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second
#define pop_f pop_front
#define pop_b pop_back

int arr[400005],size;

void construct(){
    for(int i=size; i>0; i--)
        arr[i] = arr[i*2]*arr[i*2+1];
}

void update(int idx, int val){
    if(val > 0) val = 1;
    else if(val < 0) val = -1;
    arr[idx] = val;
    while(idx > 1){
        idx /= 2;
        arr[idx] = arr[idx*2]*arr[idx*2+1];
    }
}

int f(int L,int R, int vtx, int nL, int nR){
    if(R < nL || L > nR) return 1;
    if(L <= nL && nR <= R) return arr[vtx];
    int mid = (nL+nR)/2;
    return f(L,R,vtx*2,nL,mid)*f(L,R,vtx*2+1,mid+1,nR);
}
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
        size = 0;
        int lv = 0,a,b;
        while(pow(2,lv) < n)
            size += pow(2,lv++);

        for(int i=1; i<=size+1; i++)
            arr[size+i] = 1;
        for(int i=1; i<=n; i++){
            scanf(" %d",&a);
            if(a < 0) arr[size+i] = -1;
            else if(a > 0) arr[size+i] = 1;
            else arr[size+i] = 0;
        }
        construct();

        for(int i=0; i<k; i++){
            char q;
            scanf(" %c %d %d",&q,&a,&b);
            if(q == 'C') update(size+a,b);
            else{
                int res = f(a,b,1,1,size+1);
                if(res == 0) printf("0");
                else if(res == 1) printf("+");
                else printf("-");
            }
        }
        printf("\n");
    }
}


