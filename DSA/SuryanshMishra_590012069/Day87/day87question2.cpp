#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <cstddef>

using namespace std;

// Dijkstra's algorithm for non-negative weighted graphs.
// n: number of vertices, edges: list of (u,v,w) directed edges (use undirected by adding reverse edges).
// source: source vertex. Returns vector of distances (long long) with INF for unreachable.
vector<long long> dijkstra(int n, const vector<tuple<int,int,long long>>& edges, int source) {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<vector<pair<int,long long>>> adj(n);
    for (const auto &e : edges) {
        int u = (int) get<0>(e);
        int v = (int) get<1>(e);
        long long w = (long long) get<2>(e);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back({v, w});
        }
    }

    vector<long long> dist(n, INF);
    if (n <= 0) return dist;
    if (source < 0 || source >= n) return dist;
    dist[source] = 0;

    using pli = pair<long long,int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        long long d = top.first;
        int u = top.second;
        if (d != dist[u]) continue; // stale entry
        for (auto &ed : adj[u]) {
            int v = ed.first; long long w = ed.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Wrapper to run Dijkstra on undirected graphs: caller should provide both directions if needed.

