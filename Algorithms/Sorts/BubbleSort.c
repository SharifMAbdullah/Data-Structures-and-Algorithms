#include<stdio.h>
void sort_ascending(int a[10000], int n)
{
int i,j,k;
for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
        {
        if(a[i]>a[j])
            {
            k=a[j];
            a[j]=a[i];
            a[i]=k;
            }
        }
    }
}

void sort_descending(int a[10000], int n)
{
int i,j,k;
for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
        {
        if(a[i]<a[j])
            {
            k=a[j];
            a[j]=a[i];
            a[i]=k;
            }
        }
    }
}
int main()
{
int n,i,a[10000];

scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);

sort_ascending(a,n);
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
