#include<bits/stdc++.h>
using namespace std;
int pre[1000];
void print_LIS(int index,int a[])
{
    if(pre[index]!=-1)
    {
        print_LIS(pre[index],a);
        cout<<a[index]<<" ";
    }
}

int main()
{
    int n,a[100],l[1000],maxLength = 0,maxIndex = 0;
    a[0]=INT_MIN;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    l[0] = 0;
    pre[0] = -1;
    for(int i=1;i<=n;i++)
        {
            l[i] = 0;
        for(int j=0;j<i;j++)
            {
                if(a[j] < a[i] && l[j]+1 > l[i])
                {
                    l[i] = l[j] + 1;
                    pre[i] = j;
                }
            }
            
        if(l[i] > maxLength)
            {
                maxLength = l[i];
                maxIndex = i;
                    
            }
            
        }
    printf("Longest Increasing Subsequence is : ");
    print_LIS(maxIndex,a);
    printf("\nwhich is of %d length",maxLength);
}