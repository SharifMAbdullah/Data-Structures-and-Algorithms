#include<bits/stdc++.h>
using namespace std;
int pre[1000];

void print_LIS(int a[],int index,int lp[])
{
    int newL=index;
    int q=lp[index];
    int p[newL]={};

  for(int i=1;i<=newL;i++)
  {
    p[newL-i]=a[q];
    q=pre[q];
  }

  for(int i=0;i<newL;i++)
    printf("%d ",p[i]);
}

int main()
{
    int s,h,n,a[1000],l[1000],lp[1000];
    a[0] = 0;
    l[0] = INT_MIN;
    lp[0] = -1;
    pre[0] = -1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    int temp = 0;
    a[0]=INT_MIN;
    for(int i=1;i<=n;i++)
        {
            if(l[temp-1] < a[i])
                {
                    l[temp] = a[i];
                    temp++;
                    lp[temp] = i;
                    pre[i] = lp[temp-1];
                }
            else
            {
                s =0, h = temp;
                while(s<h)
                {
                    int m = (s+h)/2;
                    if(l[m] < a[i])
                        s = m+1;
                    else
                        h = m;
                }
                
                l[s] = a[i];
                lp[s+1] = i;
                pre[i] = lp[s]; 
            }
            
        }
    int index = temp, newL = temp;
    printf("max length is %d \n",newL);
    print_LIS(a,index,lp);
}