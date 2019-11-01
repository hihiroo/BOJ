// 스택

#include <stack>
#include <iostream>
#include <stdio.h>
using namespace std;
stack <int> S;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        if(a=="push")
        {
            int b;
            cin>>b;
            S.push(b);
        }
        else if(a=="top")
        {
            if(!S.empty()) printf("%d\n",S.top());
            else printf("-1\n");
        }
        else if(a=="size") printf("%d\n",S.size());
        else if(a=="empty") printf("%d\n",S.empty());
        else if(a=="pop")
        {
            if(S.empty()) printf("-1\n");
            else {
                printf("%d\n",S.top());
                S.pop();
            }
        }
    }
}


