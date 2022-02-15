#include<bits/stdc++.h>
using namespace std;
int matrix[1000][1000];
int row,col;

void print(int i, int j)
{
    if(i==0 || j==col+1 || j==0)
        return;

    if((matrix[i-1][j-1] <= matrix[i-1][j]) && (matrix[i-1][j-1] <= matrix[i-1][j+1]))
        print(i-1, j-1);

    else if((matrix[i-1][j] <= matrix[i-1][j-1]) && (matrix[i-1][j] <= matrix[i-1][j+1]))
        print(i-1, j);

    else if((matrix[i-1][j+1] <= matrix[i-1][j-1]) && (matrix[i-1][j+1] <= matrix[i-1][j]))
        print(i-1, j+1);

    cout<<i<<" "<<j<<endl;
}

void rock_climb(int m,int n,int a[][1000])
{
    for(int i=1;i<n;i++)
    matrix[0][i] = 0;
    for(int j=0;j<=m+1;j++)
        {
            matrix[j][0] = INT_MAX;
            matrix[j][n+1] = INT_MAX;
        }
    for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1) 
                    matrix[i][j] = a[i][j];
                else
                    matrix[i][j] = a[i][j] + min( min(matrix[i-1][j-1], matrix[i-1][j]), matrix[i-1][j+1]);
            }
        }
}

int main()
{
    int a[1000][1000];
    scanf("%d%d",&row,&col);
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
            scanf("%d",&a[i][j]);

    rock_climb(row,col,a);
    
    int result[100];
    for(int i=1; i<=col; i++)
        result[i-1]=matrix[row][i];
        
    cout<<"Least danger: "<<*min_element(result, result+col)<<endl;
    cout << "which can be obtained in path" << endl;
    print(row, min_element(result, result+col)-result+1);
}