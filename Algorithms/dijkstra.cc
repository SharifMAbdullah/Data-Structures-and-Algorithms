#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Data {
	int u, d;
	Data() { }
	Data(int u, int d) : u(u), d(d) { }		// initializer list (?)
};

struct Comparator {
	// return true: meaning u is less than v
	bool operator() (Data& u, Data& v) {
		return u.d > v.d;
	}
};

const int inf = 0x3f3f3f3f;		// 1.6e9
const int N = 1e5 + 7;

vector<int> adj[N], cost[N];
int dist[N], previous[N];

int dijkstra(int n, int src, int des) {
	fill(dist, dist + n, inf);
	fill(previous, previous + n, -1);
	dist[src] = 0;

	priority_queue<Data, vector<Data>, Comparator> pq;
	pq.push(Data(src, dist[src]));

	while(!pq.empty()) {
		auto top = pq.top();
		pq.pop();

		int u = top.u, d = top.d;
		cerr << u << " " << d << " popped\n";
		if(dist[u] < d) continue;	// OPTIMIZATION

		for(int i=0; i<(int) adj[u].size(); ++i) {
			int v = adj[u][i], w = cost[u][i];
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				previous[v] = u;
				pq.push(Data(v, dist[v]));
				cerr << v << " updated with " << dist[v] << " by " << previous[v] << "\n";
			}
		}
	}

	return dist[des];
}

vector<int> construct_path(int n, int src, int des) {
	dijkstra(n, src, des);
	if(previous[des] == -1) return vector<int>();

	vector<int> path;
	int cur = des;

	while(cur != src) {
		path.push_back(cur);
		cur = previous[cur];
	}
	path.push_back(src);
	reverse(path.begin(), path.end());
	return path;
}

int main() {
	int n, m;
	cin >> n >> m;

	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back(v);
		cost[u].push_back(w);

		adj[v].push_back(u);
		cost[v].push_back(w);
	}

	int src, dest;
	cin >> src >> dest;

	// int res = dijkstra(n, src, dest);
	// cout << res << "\n";

	auto path = construct_path(n, src, dest);
	for(int v : path) cout << v << " -> ";
	cout << "\n";

	return 0;
}

// for each vertex v:
// 	dist[v] = inf
// 	prev[v] = null

// create vertex set / priority queue Q

// dist[src] = 0
// push (src, 0) into Q

// while Q not empty:
// 	(u, d) = Q top
// 	Q pop

// 	if d > dist[u]:
// 		continue

// 	for each vertex v from u:
// 		if dist[v] > dist[u] + (u to v edge weight w)
// 			dist[v] = dist[u] + (u to v edge weight w)
// 			prev[v] = u
// 			push (v, dist[v]) into Q
