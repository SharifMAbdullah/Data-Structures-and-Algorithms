#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

void lcs(string s1, string s2, int m, int n)
{
  int matrix[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
        if (i == 0 || j == 0)
            {
                if(!i) matrix[i][j] = j;
                if(!j) matrix[i][j] = i;
            }
        else if (s1[i-1] == s2[j-1]) 
            matrix[i][j] = matrix[i-1][j-1];
        else
        matrix[i][j] = 1 + min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]},comp);
    }
  }

  int index = matrix[m][n];
  
  cout <<  "Minimum edit distance is : " << index << "\n";
}

int main() {
  string s1,s2; 
  cin >> s1 >> s2;
  int m = s1.size();
  int n = s2.size();

  lcs(s1, s2, m, n);
}