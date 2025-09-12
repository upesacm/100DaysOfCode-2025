#include <vector>
#include <algorithm>
#include <tuple>
#include <cstddef>
#include <functional>

using namespace std;

// Kruskal's algorithm: find MST cost in weighted undirected graph.
// n: number of vertices, edges: undirected edges (u,v,w).
// Returns MST cost (sum of edge weights in MST), or -1 if not connected.
long long kruskalMST(int n, const vector<tuple<int,int,long long>>& edges) {
    if (n <= 0) return 0;
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    function<int(int)> find = [&](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };
    auto unite = [&](int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pb] < rank[pa]) parent[pb] = pa;
        else { parent[pb] = pa; rank[pa]++; }
        return true;
    };
    vector<tuple<long long,int,int>> sorted;
    for (const auto &e : edges) {
        int u = (int) get<0>(e);
        int v = (int) get<1>(e);
        long long w = (long long) get<2>(e);
        sorted.push_back({w, u, v});
    }
    sort(sorted.begin(), sorted.end());
    long long cost = 0;
    int count = 0;
    for (const auto &e : sorted) {
        long long w = get<0>(e);
        int u = get<1>(e), v = get<2>(e);
        if (unite(u, v)) {
            cost += w;
            ++count;
        }
    }
    return count == n-1 ? cost : -1;
}
