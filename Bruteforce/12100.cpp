//2048(easy)
#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define mp make_pair
#define fst first
#define snd second
using namespace std;

#define matrix vector<vector<int> >
int n, ans;

vector<int> pullR(vector<int> v){
    for(int j=n-2; j>=0; j--){
        int k = j;
        while(k < n-1 && !v[k+1]){
            v[k+1] = v[k];
            v[k++] = 0;
        }
    }
    return v;
}

vector<int> pullL(vector<int> v){
    for(int i=1; i<n; i++){
        int k = i;
        while(k > 0 && !v[k-1]){
            v[k-1] = v[k];
            v[k--] = 0;
        }
    }
    return v;
}

matrix pullU(matrix v){
    for(int i=0; i<n; i++){//c
        for(int j=1; j<n; j++){
            int k = j;
            while(k>0 && !v[k-1][i]){
                v[k-1][i] = v[k][i];
                v[k--][i] = 0;
            }
        }
    }
    return v;
}

matrix pullD(matrix v){
    for(int i=0; i<n; i++){
        for(int j=n-2; j>=0; j--){
            int k = j;
            while(k<n-1 && !v[k+1][i]){
                v[k+1][i] = v[k][i];
                v[k++][i] = 0;
            }
        }
    }
    return v;
}

matrix rMove(matrix v){
    for(int i=0; i<n; i++){
        v[i] = pullR(v[i]);

        for(int j=n-1; j>0; j--){
            if(v[i][j] == v[i][j-1]){
                v[i][j] *= 2;
                v[i][--j] = 0;
            }
        }
        v[i] = pullR(v[i]);
    }
    return v;
}

matrix lMove(matrix v){
    for(int i=0; i<n; i++){
        v[i] = pullL(v[i]);

        for(int j=0; j<n-1; j++){
            if(v[i][j] == v[i][j+1]){
                v[i][j] *= 2;
                v[i][++j] = 0;
            }
        }
        v[i] = pullL(v[i]);
    }
    return v;
}

matrix dMove(matrix v){
    v = pullD(v);

    for(int i=0; i<n; i++){
        for(int j=n-1; j>0; j--){
            if(v[j][i] == v[j-1][i]){
                v[j][i] *= 2;
                v[--j][i] = 0;
            }
        }
    }
    return pullD(v);
}

matrix uMove(matrix v){
    v = pullU(v);

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(v[j][i] == v[j+1][i]){
                v[j][i] *= 2;
                v[++j][i] = 0;
            }
        }
    }
    return pullU(v);
}

void f(int cnt, matrix v){
    if(cnt == 5){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans = max(ans,v[i][j]);
        return;
    }

    f(cnt+1,lMove(v));
    f(cnt+1,rMove(v));
    f(cnt+1,dMove(v));
    f(cnt+1,uMove(v));
}

int main(){
    matrix arr(30);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0, a; j<n; j++)
            cin >> a, arr[i].pb(a);

    f(0,arr);
    cout << ans;
}
