#include<stdio.h>

void merge( int a[10000], int LowerBound, int mid, int UpperBound)
{
int i,j,k,b[10000];

i= LowerBound;
j= mid+1;
k= LowerBound;

while( i<=mid && j<=UpperBound)
    {
    if( a[i]<=a[j] )
        {
        b[k]= a[i];
        i++;
        }
    else
        {
        b[k]= a[j];
        j++;
        }
    k++;
    }
if(i>mid)
    {
    while(j<=UpperBound)
        {
        b[k]= a[j];
        j++;
        k++;
        }
    }
else
    {
    while(i<=mid)
        {
        b[k]= a[i];
        i++;
        k++;
        }
    }
for(k=LowerBound; k<=UpperBound; k++)
    a[k]= b[k];
}

void MergeSort( int a[10000], int LowerBound, int UpperBound)
{
int mid;

if(LowerBound < UpperBound)
    {
    mid= (LowerBound+UpperBound)/2;
    MergeSort (a, LowerBound, mid);
    MergeSort (a, mid+1, UpperBound);
    merge (a, LowerBound, mid, UpperBound);
    }
}

int main()
{
int n,i,a[10000],b[10000];

printf("Enter number of elements: \n");
scanf("%d",&n);
printf("Enter elements: \n");

for(i=0;i<n;i++)
scanf("%d",&a[i]);

MergeSort(a,0,n-1);

for(i=0;i<n;i++)
printf("%d ",a[i]);
}
