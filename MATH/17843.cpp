//시계
#include<bits/stdc++.h>
#define lli long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define matrix vector<vector<int> >
#define cinFast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        double h,m,s;
        cin >> h >> m >> s;

        double s_angle = s*6;
        double m_angle = (s + m*60)/10.0;
        double h_angle = (s + m*60 + h*3600)/120.0;

        double x = abs(s_angle-m_angle);
        x = min(x,360-x);

        double y = abs(s_angle-h_angle);
        y = min(y,360-y);

        double z = abs(m_angle-h_angle);
        z = min(z,360-z);

        printf("%.6f\n",min(x,min(y,z)));
    }
}