#include <vector>
#include <functional>
#include <cstddef>

using namespace std;

// Recursive DFS traversal of an undirected graph starting from node 0.
// Input: n = number of vertices, edges = list of undirected edges (pairs {u,v}).
// Output: vector<int> containing vertices in DFS preorder reachable from 0.
vector<int> dfsTraversal(int n, const vector<pair<int,int>>& edges) {
    vector<int> order;
    if (n <= 0) return order;

    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<bool> seen(n, false);
    function<void(int)> dfs = [&](int u) {
        seen[u] = true;
        order.push_back(u);
        for (int v : adj[u]) {
            if (!seen[v]) dfs(v);
        }
    };

    dfs(0);
    return order;
}
