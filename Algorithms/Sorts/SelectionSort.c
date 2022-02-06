#include<stdio.h>
int main()
{
int n,i,j,min,temp,a[10000];

scanf("%d",&n);
for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }

for(i=0;i<n;i++)
    {
    min=i;
    for(j=i+1; j<n; j++)
        {
        if (a[j]< a[min])
        min=j;
        }
    temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    }
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
