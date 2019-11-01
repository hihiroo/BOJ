// 괄호

#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,check=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        int check=0;
        stack <int> S;
        for(int i=0;i<a.length();i++)
        {
            if(a.at(i)=='(') S.push('(');
            else
            {
                if(S.empty())
                {
                    check=1;
                    printf("NO\n");
                    break;
                }
                else S.pop();
            }
        }
        if(check) continue;
        if(!S.empty())printf("NO\n");
        else printf("YES\n");
    }
}



