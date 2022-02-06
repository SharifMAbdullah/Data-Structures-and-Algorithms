#include<stdio.h>
#include<string.h>

int getMax(int a[], int n)
{
int i,max=a[0];

for(i=1;i<n;i++)
    {
    if(max<a[i])
    max=a[i];
    }
return max;
}

void countSort(int a[], int n, int pos)
{
int k,i, count[10000],b[10000];
memset(count,0, n*sizeof(count[0]) );

for(i=0;i<n;i++)
    count[ (a[i]/pos)% 10]++;

for(i=1;i<=n;i++)
    count[i] += count[i-1];

for(i=n-1; i>=0; i--)
    b[--count [ (a[i]/pos)% 10] ] = a[i];

for(i=0;i<n;i++)
    a[i]=b[i];
}


void radixSort(int a[],int n)
{
int pos, max=getMax(a,n);

for(pos=1; max/pos>0; pos*=10)
    countSort(a,n,pos);
}

int main()
{
int n,i,a[10000];
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%d",&a[i]);

radixSort(a,n);

for(i=0;i<n;i++)
printf("%d ",a[i]);
}
