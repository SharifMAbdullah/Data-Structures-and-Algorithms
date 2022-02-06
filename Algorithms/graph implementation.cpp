#include <bits/stdc++.h>
using namespace std;
int graph[1000][1000];

int main()
{
    int node;
    cout << "Enter number of node: ";
    cin >> node;
    int a, b;
    cout << "Enter the edges(2 at a time): " << endl;

    // initialize
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            graph[i][j] = 0;
        }
    }

    while (1)
    {
        cin >> a; // 2
        cin >> b; // 3
        if (a == -1 && b == -1)
        {
            break;
        }
        else
        {
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    while (1)
    {
        cout << "Enter nodes for checking (2 at a time): " << endl;
        int x, y;
        cin >> x;
        cin >> y;

        if (x == -1 || y == -1)
            break;

        if (graph[x][y] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
