#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[100],i,j,k,n,l=0,r,mid,data,count1=0,count2=0;
printf("Enter the amount of data you want to input:");
scanf("%d",&n);
data=rand();
r=n-1;

 for(i=0;i<n;i++)
    {
    a[i]=rand();
    }

for(i=0;i<n;i++)
    {
    for(j=i+1;j<=n-1;j++)
        {
        if(a[i]>a[j])
            {
            count1++;
            k=a[j];
            a[j]=a[i];
            a[i]=k;
            }
        }
    }
while(l<=r)
    {count2++;
    mid=(l+r)/2;
    if (data==a[mid])
        break;
    else if (data<a[mid])
        r=mid-1;
    else l=mid+1;
    continue;
    if(l>r) printf("Not found");
    }
printf("Excecuted statements: %d",count1+count2);
}
