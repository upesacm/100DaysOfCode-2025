#include <vector>
#include <cstddef>
#include <functional>

using namespace std;

// Hamiltonian path detection using backtracking in undirected graph.
// n: number of vertices, edges: undirected edges.
// Returns true if a Hamiltonian path exists, false otherwise.
bool hasHamiltonianPath(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return false;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<char> visited(n, 0);
    function<bool(int,int)> dfs = [&](int u, int count) {
        if (count == n) return true;
        visited[u] = 1;
        for (int v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, count+1)) return true;
            }
        }
        visited[u] = 0;
        return false;
    };
    // Try starting from every vertex
    for (int start = 0; start < n; ++start) {
        fill(visited.begin(), visited.end(), 0);
        if (dfs(start, 1)) return true;
    }
    return false;
}
