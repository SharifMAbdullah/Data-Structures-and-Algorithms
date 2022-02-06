#include<bits/stdc++.h>
using namespace std;

const int N = 100;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define RED -5
#define BLUE 5
#define NIL -1
#define INF 1e8 + 5

int graph [ N ] [ N ] ;
int color[N];
int prevv[N];
int d[N];

void bfs(int source)
{
    for(int i=0;i<N;i++)
    {
        color[i] = WHITE;
        prevv[i] = NIL;
        d[i] = INF;
    }

    color[source] = GREY;
    d[source] = 0;
    prevv[source] = NIL;
    queue <int> q;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0;v<N;v++)
        {
            if(graph[u][v]==1)
            {
                if(color[v]==WHITE)
                {
                color[v] = GREY;
                d[v] = d[u] + 1;
                prevv[v] = u;
                q.push(v);
                }
            }

        }
        color[u] = BLACK;
    }
}

void print_path(int source, int dest){

	if (source == dest){
		cout << source << " ";
	}
	else if (prevv[dest] == NIL){
		cout << "No path\n";
	}
	else {
		print_path(source,prevv[dest]);
		cout << dest << " ";
	}
}


bool check_bipartite(int source,int node)
{
    color[N] = {WHITE};
    queue <int> q;

    color[source] = BLUE;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        //self loop
        if(graph[u][u]==1) return false;

        //find all non-colored adjacent vertices
        for(int v=0;v<node;v++)
        {
            //check if a not colored vertex exists
            if(graph[u][v]==1 && color[v]==WHITE)
            {
                //assign inverse color of the node u to node v
                color[v] = -1 * color[u];
                q.push(v);
            }

            //check if node u and v are of the same color
            else if (graph[u][v]==1 && color[v] == color[u])
                return false;
        }

    }
    //reaching here means all vertices can be colored but no two adjacent
    //vertex will be of same color
    return true;
}

int main()
{
    int n;

    cout << "Enter number of nodes" << endl;
    cin  >> n;

    cout << "Enter the elements of graph as u v, enter -1 -1 to stop" << endl;
        while(1)
        {
            int u,v;
            cin >> u >> v;

            if(u == -1 && v == -1) break;

            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        cout << "Enter 1 to print shortest path, 2 to check bipartite" << endl;
        int choice;
        cin >> choice;

    if(choice==1)
    {
        cout << "Enter the source and destination: " << endl;
        int source,v;
        cin >> source >> v;
        cout << endl;

        bfs(source);
        cout << "Shortest path from " << source << " to " << v << " is: " << endl;
        print_path(source,v);
        puts("");
    }

    else
    {
        cout << "Enter the source" << endl;
        int source;
        cin >> source;
        cout << endl;
        if(check_bipartite(source,n)) cout << "The graph is bipartite" << endl;
        else cout << "The graph is NOT bipartite" << endl;
    }

}
