#include <vector>
#include <stack>
#include <cstddef>
#include <functional>

using namespace std;

// Kosaraju's algorithm: count strongly connected components in a directed graph.
// n: number of vertices, edges: directed edges (u->v).
// Returns number of SCCs.
int kosarajuSCCCount(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return 0;
    vector<vector<int>> adj(n), radj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
    }
    vector<char> seen(n, 0);
    vector<int> order;
    // First pass: DFS to get finish order
    function<void(int)> dfs1 = [&](int u) {
        seen[u] = 1;
        for (int v : adj[u]) if (!seen[v]) dfs1(v);
        order.push_back(u);
    };
    for (int i = 0; i < n; ++i) if (!seen[i]) dfs1(i);
    // Second pass: DFS on transpose graph in reverse finish order
    int scc = 0;
    fill(seen.begin(), seen.end(), 0);
    function<void(int)> dfs2 = [&](int u) {
        seen[u] = 1;
        for (int v : radj[u]) if (!seen[v]) dfs2(v);
    };
    for (int i = n-1; i >= 0; --i) {
        int u = order[i];
        if (!seen[u]) {
            ++scc;
            dfs2(u);
        }
    }
    return scc;
}
