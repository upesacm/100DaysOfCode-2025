#include <vector>
#include <tuple>
#include <limits>
#include <cstddef>

using namespace std;

// Bellman-Ford algorithm (LeetCode-style helpers, no main).
// - bellmanFord returns shortest distances from source to all vertices.
//   Unreachable vertices will have value numeric_limits<long long>::max()/4.
// - detectNegativeCycleGlobal returns true if there exists any negative-weight cycle
//   anywhere in the directed graph (not necessarily reachable from a single source).

// Compute shortest distances from `source` using Bellman-Ford.
// n: number of vertices (0..n-1), edges: list of (u,v,w) directed edges.
vector<long long> bellmanFord(int n, const vector<tuple<int,int,long long>>& edges, int source) {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    if (n <= 0) return dist;
    if (source < 0 || source >= n) return dist;
    dist[source] = 0;

    for (int iter = 0; iter < n - 1; ++iter) {
        bool updated = false;
        for (const auto &e : edges) {
            int u, v; long long w;
            tie(u, v, w) = e;
            if (u < 0 || u >= n || v < 0 || v >= n) continue;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }
    return dist;
}

// Detect a negative-weight cycle anywhere in the graph using Bellman-Ford style
// relaxation. This runs a global detection by initializing all distances to 0
// and performing n iterations. If an update occurs on the nth iteration, a
// negative cycle exists.
bool detectNegativeCycleGlobal(int n, const vector<tuple<int,int,long long>>& edges) {
    if (n <= 0) return false;
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, 0); // start from 0 for all nodes to detect any negative cycle

    for (int iter = 0; iter < n; ++iter) {
        bool updated = false;
        for (const auto &e : edges) {
            int u, v; long long w;
            tie(u, v, w) = e;
            if (u < 0 || u >= n || v < 0 || v >= n) continue;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) return false; // no further relaxations -> no negative cycle
        if (iter == n - 1 && updated) return true; // update in nth iteration -> negative cycle
    }
    return false;
}

// Convenience wrapper: run Bellman-Ford and report distances; throw no exceptions here.
// Example usage (pseudo):
//   vector<tuple<int,int,long long>> edges = {{0,1,-1},{0,2,4},...};
//   auto d = bellmanFord(5, edges, 0);
//   bool hasNegCycle = detectNegativeCycleGlobal(5, edges);

