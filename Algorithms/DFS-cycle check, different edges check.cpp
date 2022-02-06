#include<bits/stdc++.h>
using namespace std;
#define N 100
#define WHITE 1
#define GREY 2
#define BLACK 3
#define NIL -1
#define INF 1e8 + 5

int graph[N + 1][N + 1];
int prevv[N + 1];
int color[N + 1];
int f[N + 1];
int timee;
int d[N + 1] = {-1};
int node;

void DFS_visit(int u)
{
    color[u] = GREY;
    timee++;
    d[u] = timee;

    for(int v=0;v<node;v++)
    {
        if(graph[u][v] && color[v]==WHITE)
        {
            prevv[v] = u;
            cout <<" TREE EDGE: " <<" U= " << u << " V= " << v << endl;
            DFS_visit(v);
        }

        else if(graph[u][v] && color[v]==GREY)
        {
             cout <<"< BACK EDGE: " << "U: " << u << " V: " << v << endl;
             cout << " Cycle Exists" << endl;
        }

        else if(graph[u][v] && color[v]==BLACK)
        {
            if(d[u]<d[v]) cout <<"FORWARD EDGE: " << "U: " << u << " V: " << v << endl;
            else if(d[u]>d[v]) cout <<"X CROSS EDGE: " << "U: " << u << " V: " << v << endl;
        }
    }

    color[u] = BLACK;
    timee++;
    f[u] = timee;
}

void DFS()
{
    for(int u=0;u<node;u++)
    {
        color[u] = WHITE;
        prevv[u] = NIL;
        f[u] = INF;
        d[u] = INF;
    }

    timee = 0;
    for(int u=0;u<node;u++)
    {
        if(color[u]==WHITE)
            {
                cout << "\nSOURCE: " << u << endl;
                DFS_visit(u);
            }
    }
}

int main()
{
    cout << "Enter number of nodes: " << endl;
    cin >> node;

    cout << "Enter the elements of graph as x y, enter -1 -1 to stop: " << endl;
    int x,y;
    while (1)
    {
        cin >> x >> y;
        if(x==-1 || y==-1) break;

        graph[x][y] = 1;//Directed graph, hence only element at graph[x][y] needs to be updated
                        //to show there exists an edge from x to y
    }

    DFS();
}
