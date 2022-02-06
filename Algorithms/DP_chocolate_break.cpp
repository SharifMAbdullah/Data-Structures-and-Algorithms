#include<bits/stdc++.h>
using namespace std;

int cc[1000][1000],profit[1000][1000];

int cc_cut(int w, int l)
{
    if(cc[w][l]>-1) return cc[w][l];
    
    int lcut = -32000;
    int wcut = -32000;
    
    for(int i=1;i<=w;i++)
        lcut = max(lcut,profit[i][l]+cc_cut(w-i,l));

    for(int i=1;i<=l;i++)
        wcut = max(wcut,profit[w][i]+cc_cut(w,l-i));
    
    cc[w][l] = max(lcut,wcut);
     
return cc[w][l];
}

int main()
{
    int width, length;
    scanf("%d%d",&width,&length);
    
    for(int i=1;i<=width;i++)
    {
        for(int j=1;j<=length;j++)
        scanf("%d",&profit[i][j]);
    }
    
    for(int i=0;i<=width;i++)
        cc[i][0]=0;
        
    for(int i=0;i<=length;i++)
        cc[0][i]=0;
        
    for(int i=1;i<=width;i++)
    {
        for(int j=1;j<=length;j++)
        cc[i][j] = -1;
    }
    cout<< "Max profit that can be obtained is : "<<cc_cut(width,length);
    return 0;
}
