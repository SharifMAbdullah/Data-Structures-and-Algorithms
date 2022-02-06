#include<stdio.h>
int main()
{
int current,n,i,j,gap,temp,a[10000];

scanf("%d",&n);
for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
for(i=1;i<n;i++)
    {
    current= a[i];
    gap= i;
    while( gap> 0 && a[gap-1]> current)
        {
        a[gap] = a[gap-1];
        gap--;
        }
    }
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
