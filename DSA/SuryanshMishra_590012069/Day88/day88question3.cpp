#include <vector>
#include <queue>
#include <cstddef>

using namespace std;

// Check if an undirected graph is bipartite using BFS coloring.
// n: number of vertices, edges: undirected edges.
// Returns true if graph is bipartite, false otherwise.
bool isBipartite(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return true;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<int> color(n, -1); // -1: uncolored, 0/1: two colors
    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) continue;
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}
