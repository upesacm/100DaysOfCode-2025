#include <vector>
#include <queue>
#include <cstddef>
#include <tuple>

using namespace std;

// Prim's algorithm: find MST cost in weighted undirected graph.
// n: number of vertices, edges: undirected edges (u,v,w).
// Returns MST cost (sum of edge weights in MST), or -1 if not connected.
long long primMST(int n, const vector<tuple<int,int,long long>>& edges) {
    if (n <= 0) return 0;
    vector<vector<pair<int,long long>>> adj(n);
    for (const auto &e : edges) {
        int u = (int) get<0>(e);
        int v = (int) get<1>(e);
        long long w = (long long) get<2>(e);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    vector<char> visited(n, 0);
    using pli = pair<long long,int>; // (weight, vertex)
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 0}); // start from vertex 0
    long long cost = 0;
    int count = 0;
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        long long w = top.first;
        int u = top.second;
        if (visited[u]) continue;
        visited[u] = 1;
        cost += w;
        ++count;
        for (auto &ed : adj[u]) {
            int v = ed.first; long long ew = ed.second;
            if (!visited[v]) pq.push({ew, v});
        }
    }
    return count == n ? cost : -1;
}
