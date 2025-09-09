#include <vector>
#include <queue>
#include <cstddef>

using namespace std;

// BFS traversal of an undirected graph starting from node 0.
// Input: n = number of vertices, edges = list of undirected edges (pairs {u,v}).
// Output: vector<int> containing vertices in BFS order reachable from 0.
vector<int> bfsTraversal(int n, const vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> order;
    if (n <= 0) return order;
    vector<bool> seen(n, false);
    queue<int> q;
    q.push(0); seen[0] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}
