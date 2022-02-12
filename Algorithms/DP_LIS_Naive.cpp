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
    int n = 10,a[100],l[1000],maxLength = 0,maxIndex = 0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    l[0] = 0;
    pre[0] = -1;
    for(int i=1;i<=n;i++)
        {
            l[i] = 0;
        for(int j=0;j<=i-1;j++)
            {
                if(a[j] < a[i] && l[j]+1 > l[i])
                {l[i] = l[j] + 1;
                pre[i] = j;}
                
                if(l[i] > maxLength)
                {
                    maxLength = l[i];
                    maxIndex = i;
                    
                }
            }
        }
    print_LIS(maxIndex,a);
    printf("\n%d ",maxLength+1);
}