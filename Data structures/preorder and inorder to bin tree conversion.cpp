#include<bits/stdc++.h>
using namespace std;

int j=99,k=0,inorder[100], output[100], preorder[100], n;

void findRootofSubTree(int position,int start,int end)
{

     if(start>end)
        return ;

     {int t=start;
     k++;
     while(inorder[t]!=preorder[k])
       t++;
      output[position]=inorder[t];

        findRootofSubTree(position*2+1,start,t-1);
        findRootofSubTree(position*2+2,t+1,end);}
}


void divideSubTree(int root)
{
    int i=0,position=0;
    while(inorder[i]!=root)
        i++;

    findRootofSubTree(position*2+1,0,i-1);
    findRootofSubTree(position*2+2,i+1,n-1);

}


int main()
{
    int i;

    printf("Enter the number of elements you want to insert:\n");
    scanf("%d",&n);

    printf("Enter the elements in pre order format:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }

    printf("Enter the elements in in order format:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }

   // printf("The root is %d \n",preorder[0]);
    int root = preorder[0];
    output[0] = preorder[0];
    //preorder[0] = -123;
    divideSubTree(root);
     while(output[j]=='\0')
     j--;
    //cout<<j;
    for(i=0;i<=j;i++)
    printf("%d ",output[i]);
}
