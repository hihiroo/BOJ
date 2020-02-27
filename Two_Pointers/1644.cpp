//소수의 연속합
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define lli long long int
#define fst first
#define snd second

vector <int> prime;
bool chk[4000000];

int main()
{
   int N; cin >> N;
   for(int i = 2; i <= N; i++)
      if(chk[i] == 0)
      {
         for(int j = i*i; j <= N; j += i)
            chk[j] = 1;
      }

   for(int i = 2; i <= N; i++)
      if(chk[i] == 0) prime.push_back(i);

   // for(int i = 0; i < prime.size(); i++)
   // {
   //    cout << prime[i] << ' ';
   // }
   int s = 0;
   int cnt = 0;

   while(prime[s] <= N)
   {
      int i = s;
      int sum = 0;
      while(sum < N){
         sum += prime[i++];
         cout << sum << ' ';
      }
      cout << '\n';
      if(sum == N) cnt++;
      s++;
   }
   cout << cnt;
}
