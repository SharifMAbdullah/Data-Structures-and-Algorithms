#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, int m, int n)
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
  char storeTable[index + 1];
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
  
  cout <<  "Longest common subsequence of the given strings is : " << storeTable << "\n";
}

int main() {
  string s1,s2; 
  cin >> s1 >> s2;
  int m = s1.size();
  int n = s2.size();

  lcs(s1, s2, m, n);
}