#include <bits/stdc++.h>
using namespace std;

void lcs(int s1[], int s2[], int m, int n)
{
  int matrix[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        matrix[i][j] = 0;
      else if (s1[i - 1] == s2[j - 1])
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      else
        matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
    }
  }

  int index = matrix[m][n];
  int storeTable[index + 1];
  storeTable[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      storeTable[index - 1] = s1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (matrix[i - 1][j] > matrix[i][j - 1])
      i--;
    else
      j--;
  }
  
  cout <<  "Longest increasing subsequence is : " <<  "\n";
  for(int i=0; storeTable[i] != '\0' ;i++)
  cout << storeTable[i] << " ";
}

int main() {
  int n,s1[100],s2[100]; 
  cin >> n;
  for(int i=0;i<n;i++)
  cin >> s1[i];
    
  for(int i=0;i<n;i++)
  s2[i] = s1[i];
  
  int m = n;
  sort(s2,s2+n);

  
  lcs(s1, s2, m, n);
}