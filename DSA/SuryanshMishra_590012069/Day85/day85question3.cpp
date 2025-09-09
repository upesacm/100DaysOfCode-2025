#include <vector>
#include <cstddef>
#include <stack>
#include <functional>

using namespace std;

// Count connected components in an undirected graph.
// Two implementations provided:
// - countComponentsDFS: traversal-based (O(n + m) time, O(n + m) space)
// - countComponentsUnionFind: union-find (amortized almost O(1) per op)

int countComponentsDFS(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return 0;
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<char> seen(n, 0);
    int components = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i]) continue;
        ++components;
        // iterative DFS
        stack<int> st;
        st.push(i);
        seen[i] = 1;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : adj[u]) {
                if (!seen[v]) {
                    seen[v] = 1;
                    st.push(v);
                }
            }
        }
    }
    return components;
}

int countComponentsUnionFind(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return 0;
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    function<int(int)> find = [&](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression (partial)
            x = parent[x];
        }
        return x;
    };

    auto unite = [&](int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pb] < rank[pa]) parent[pb] = pa;
        else { parent[pb] = pa; rank[pa]++; }
    };

    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) unite(u, v);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) if (find(i) == i) ++cnt;
    return cnt;
}

// Default wrapper: returns component count. Uses union-find by default.
int countConnectedComponents(int n, const vector<pair<int,int>>& edges) {
    return countComponentsUnionFind(n, edges);
}
