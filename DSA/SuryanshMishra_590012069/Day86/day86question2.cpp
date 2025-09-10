#include <vector>
#include <functional>
#include <cstddef>

using namespace std;

// Detect cycle in directed graph using DFS color-coding (0=unvisited,1=visiting,2=done).
bool hasDirectedCycle(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return false;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) adj[u].push_back(v);
    }

    vector<int> color(n, 0);
    function<bool(int)> dfs = [&](int u) -> bool {
        color[u] = 1; // visiting
        for (int v : adj[u]) {
            if (color[v] == 0) {
                if (dfs(v)) return true;
            } else if (color[v] == 1) {
                // found back-edge to visiting node -> cycle
                return true;
            }
        }
        color[u] = 2; // done
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            if (dfs(i)) return true;
        }
    }
    return false;
}
