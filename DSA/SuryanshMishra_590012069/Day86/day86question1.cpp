#include <vector>
#include <cstddef>
#include <functional>

using namespace std;

// Detect cycle in undirected graph using DFS with parent tracking.
static bool dfsHasCycle(const vector<vector<int>>& adj, vector<int>& seen, int u, int parent) {
    seen[u] = 1;
    for (int v : adj[u]) {
        if (!seen[v]) {
            if (dfsHasCycle(adj, seen, v, u)) return true;
        } else if (v != parent) {
            // visited and not parent => cycle
            return true;
        }
    }
    return false;
}

bool hasCycleUndirectedDFS(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return false;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<int> seen(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
            if (dfsHasCycle(adj, seen, i, -1)) return true;
        }
    }
    return false;
}

// Detect cycle using Union-Find.
int findParent(vector<int>& parent, int x) {
    if (parent[x] != x) parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

bool hasCycleUndirectedUnionFind(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return false;
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);
        if (pu == pv) return true;
        parent[pu] = pv;
    }
    return false;
}

// Default wrapper: return true if undirected graph has cycle.
bool detectCycleUndirected(int n, const vector<pair<int,int>>& edges) {
    return hasCycleUndirectedUnionFind(n, edges);
}
