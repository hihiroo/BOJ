#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int

lli arr[100005],cur[100005],rootP,cnt[500000],rootCnt[800],sizeP;

struct A{
    lli q, idx, delta, l, r, ranking;
}Q[100005];

vector<lli> possible;
map<lli,lli> appear, appear_num;

void IsNew(lli k){
    if(appear.find(k) == appear.end()){
        appear[k] = 1;
        possible.pb(k);
    }
}

int main(){
    lli n,m;
    scanf("%lld%lld",&n,&m);

    for(lli i=1; i<=n; i++){
        scanf("%lld",&arr[i]);
        cur[i] = arr[i];
        IsNew(arr[i]);
    }

    for(lli i=0; i<m; i++){
        scanf("%lld",&Q[i].q);
        if(Q[i].q <= 2){
            scanf("%lld%lld",&Q[i].idx,&Q[i].delta);
            if(Q[i].q == 2) Q[i].delta *= -1;
            cur[Q[i].idx] = cur[Q[i].idx] + Q[i].delta;
            IsNew(cur[Q[i].idx]);

        }
        else if(Q[i].q == 3){
            scanf("%lld%lld",&Q[i].l,&Q[i].r);
            IsNew(Q[i].r), IsNew(Q[i].l);
        }
        else scanf("%lld",&Q[i].ranking);
    }

    sort(possible.begin(),possible.end());

    for(lli i=0; i<possible.size(); i++)
        appear_num[possible[i]] = i;
    sizeP = possible.size();
    rootP = sqrt(sizeP);

    for(lli i=1; i<=n; i++){
        cnt[appear_num[arr[i]]]++;
        rootCnt[appear_num[arr[i]]/rootP]++;
    }
    for(lli i=0; i<m; i++){
        if(Q[i].q <= 2){
            lli original = appear_num[arr[Q[i].idx]];
            cnt[original]--, rootCnt[original/rootP]--;
            arr[Q[i].idx] += Q[i].delta;
            lli new_ = appear_num[arr[Q[i].idx]];
            cnt[new_]++, rootCnt[new_/rootP]++;
        }

        else if(Q[i].q == 3){
            lli sum = 0;
            lli l = appear_num[Q[i].l];
            lli r = appear_num[Q[i].r];
            for(lli j=l; j<=r; j++){
                if(j/rootP == l/rootP || j/rootP == r/rootP)
                    sum += cnt[j];
                else{
                    sum += rootCnt[j/rootP];
                    j += rootP-1;
                }
            }
            printf("%lld\n",sum);
        }
        else{
            lli sum = Q[i].ranking;
            for(lli j = (sizeP-1)/rootP; j>=0; j--){
                if(sum - rootCnt[j] > 0){
                    sum -= rootCnt[j];
                    continue;
                }
                for(lli k = min(sizeP,(j+1)*rootP)-1; k>=0; k--){
                    if(sum - cnt[k] <= 0){
                        printf("%lld\n",possible[k]);
                        break;
                    }
                    sum -= cnt[k];
                }
                break;
            }
        }
    }
}
