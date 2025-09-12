#include <vector>
#include <queue>
#include <limits>
#include <cstddef>

using namespace std;

// BFS-based shortest distances in unweighted graph from source.
// n: number of vertices, edges: undirected edges. Returns vector<int> distances with -1 for unreachable.
vector<int> shortestPathsUnweighted(int n, const vector<pair<int,int>>& edges, int source) {
    vector<int> dist;
    if (n <= 0) return dist;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    dist.assign(n, -1);
    if (source < 0 || source >= n) return dist;
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
