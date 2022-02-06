#include<bits/stdc++.h>
using namespace std;
int store[1000];
int bottomUp_rod_cutting(int p[],int n,int r[])
{
    int q;
    r[0] = 0;

    for(int j=1;j<=n;j++)
    {
        q = -2;
        for(int i=1;i<=j;i++)
        {
            if(q < p[i] + r[j-i])
                {
                    q = p[i] + r[j-i];
                    store[j] = i;
                }
        }
        r[j] = q;
    }
return r[n];
}

int main()
{
    int n,profits[1000],r[1000] = {};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%d",&profits[i]);
    
    int result = bottomUp_rod_cutting(profits,n,r);
    printf("Max profit is %d which is obtained form cutting the rod into following pieces:\n",result);
    
    while(n>0)
    {
        printf("%d ",store[n]);
        n=n-store[n];
    }
}