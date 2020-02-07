//수 정렬하기
#include <stdio.h>
int main()
{
    int i,j,n,arr[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf(" %d",&arr[i]);
    for(i=0;i<n;i++){
        int min=arr[i];
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<min){
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
    }
    for(i=0;i<n;i++) printf("%d\n",arr[i]);
}