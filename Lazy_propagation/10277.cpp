//JuQueen
#include <bits/stdc++.h>
#define mp make_pair
#define lli long long
#define fst first
#define snd second
#define pb push_back
#define fixed(a) cout << fixed; cout.precision(a);
#define cinFast() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int size, lazy[20000000];
pair<int,int> tree[20000000];

void propagation(int vtx){
    if(lazy[vtx]){
        if(vtx <= size){
            lazy[vtx*2] += lazy[vtx];
            lazy[vtx*2+1] += lazy[vtx];
        }
        tree[vtx].fst += lazy[vtx];
        tree[vtx].snd += lazy[vtx];
        lazy[vtx] = 0;
    }
}

pair<int,int> f(int L, int R, int vtx, int nL, int nR, int val){
    propagation(vtx);
    if(nL > R || L > nR) return mp(-1e8,1e8);
    if(L <= nL && nR <= R){
        lazy[vtx] += val;
        propagation(vtx);
        return tree[vtx];
    }

    int mid = (nL + nR)/2;
    pair<int,int> l,r;
    l = f(L,R,vtx*2,nL,mid,val);
    r = f(L,R,vtx*2+1,mid+1,nR,val);

    tree[vtx].fst = max(tree[vtx*2].fst,tree[vtx*2+1].fst);
    tree[vtx].snd = min(tree[vtx*2].snd,tree[vtx*2+1].snd);

    return mp(max(l.fst,r.fst),min(l.snd,r.snd));
}

void construct(int c){
    for(int i=size+c+1; i<=size+size+1; i++)
        tree[i] = mp(-1e8,1e8);
    for(int i=size; i>=1; i--)
        tree[i] = mp(max(tree[i*2].fst, tree[i*2+1].fst),
                     min(tree[i*2].snd,tree[i*2+1].snd));
}

int main(){
    cinFast();

    int c,n,o;
    cin >> c >> n >> o;

    int lv = 1;
    while(lv < c){
        size += lv;
        lv *= 2;
    }

    construct(c);

    while(o--){
        string q;
        cin >> q;

        if(q == "state"){
            int x;
            cin >> x;
            x++;
            f(x,x,1,1,size+1,0);
            cout << tree[size+x].fst << '\n';
        }
        else{
            int a,b,s;
            if(q == "groupchange") cin >> a >> b >> s;
            else{
                cin >> a >> s;
                b = a;
            }
            a++, b++;

            pair<int,int> can = f(a,b,1,1,size+1,0);
            if(s < 0){
                cout << -min(-s,can.snd) << '\n';
                f(a,b,1,1,size+1,-min(-s,can.snd));
            }
            else{
                cout << min(s,n-can.fst) << '\n';
                f(a,b,1,1,size+1,min(s,n-can.fst));
            }
        }
    }
}
