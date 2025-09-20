#include <vector>
#include <cstddef>

using namespace std;

// Degree-based Eulerian path/circuit detection in undirected graph.
// n: number of vertices, edges: undirected edges.
// Returns 0: none, 1: Eulerian path, 2: Eulerian circuit.
int eulerianType(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return 0;
    vector<int> degree(n, 0);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            degree[u]++;
            degree[v]++;
        }
    }
    int odd = 0;
    for (int d : degree) if (d % 2) ++odd;
    if (odd == 0) return 2; // Eulerian circuit
    if (odd == 2) return 1; // Eulerian path
    return 0; // None
}

// Helper for output
// 0: "None", 1: "Eulerian Path Exists", 2: "Eulerian Circuit Exists"
const char* eulerianTypeStr(int t) {
    if (t == 2) return "Eulerian Circuit Exists";
    if (t == 1) return "Eulerian Path Exists";
    return "None";
}
