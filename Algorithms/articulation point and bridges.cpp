#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 5;

#define WHITE 0 
#define GRAY 1
#define BLACK 2
#define RED 4
#define BLUE 5
#define NIL -1
#define INF 1e8 + 5


int color [MAX];
int discovery_time;
int prevv[MAX];
int d[MAX];
int f[MAX];
int low[MAX];
int child;
bool ap[MAX];

vector<int> articulation_points;
vector<int> adj[MAX];
vector<pair<int,int>> bridge;

void dfs_visit(int v){
	color[v] = GRAY;
	discovery_time++;
	d[v] = discovery_time;
	low[v] = d[v];
	child = 0;
	
	for (int w : adj[v]){
		//for (int i=0;i<adj[v].size();i++){
		// 	int w = adj[v][i];
		
		if (color[w] == WHITE){
			child++;
			prevv[w] = v;
			dfs_visit(w);
			
			if (low[w] < low[v]) low[v] = low[w];
			
			if (prevv[v] == NIL && child>1){
				if (ap[v] == false){
					ap[v] = true;
					articulation_points.push_back(v);
				}
			} 
			if (prevv[v] != NIL && low[w] >= d[v]){
				//record that vertex v is an articulation
				
				//cout << " current - " << w << " prev - " << v << endl;
				if (ap[v] == false){
					ap[v] = true;
					articulation_points.push_back(v);
				}
			}
			
			if (low[w] > d[v]){
				bridge.push_back({w,v});
			}
			
		}
		else if (w != prevv[v]) {
			if (d[w] < low[v]) low [v] = d[w];
		}
	}
	
	color[v] = BLACK;
	discovery_time++;
	f[v] = discovery_time;
}
void dfs(int len){
	
	for (int u=0;u<=len;u++){
		color[u] = WHITE;
		prevv[u] = NIL;
		low[u] = INF;
		f[u] = INF;
		d[u] = INF;
		ap[u] = false;
	}
	
	discovery_time = 0;
	child = 0;
	for (int u=0;u<=len;u++){
		if (color[u] == WHITE){
			dfs_visit(u);
		}
	}
}
	
int main (){
	int len; // number of nodes 
	
	cin >> len; 
	
	int u,v;
	
	while (1){
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i=0;i<=len;i++){
		cout << i << " - ";
		for (int x : adj[i]) cout << x << " , " ;
		cout << endl;
	}
	
	dfs(len);
	
	cout << "articulation points size : " << articulation_points.size() << endl;
	cout << "Articulation points: ";
	for (int i : articulation_points) cout << i << " " ;
	cout << endl;
	
	
	cout << "Bridges : \n";
	for (auto [x,y] : bridge) cout << x << " - " << y << endl;
	
	//cout << " LOW \n";
	//for (int i=0;i<=len;i++){
		//cout << "low(" << i << ") = " << low[i]<< endl;
	//}
	
}