#include<bits/stdc++.h>
using namespace std;

int partition(int *a,int lb,int ub) //lb = lower bound, ub = upper bound
{
    int pivot = a[lb];
    int start = lb, end = ub;

    if(start<end)
    {
        while(a[start] <= pivot)
        {
            start++;
        }

        while(a[end] > pivot)
        {
            end--;
        }

        if(start<end)
        {
        swap(a[start],a[end]);
        }
    }

    swap(a[lb],a[end]); // restore pivot

return end;
}

void quickSort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
    int partitionPoint = partition(a,lb,ub);
    quickSort(a,lb,partitionPoint-1);
    quickSort(a,partitionPoint+1,ub);
    }
}

int main()
{
int n,a[100];

scanf("%d",&n);
for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

quickSort(a,0,n-1);

for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
