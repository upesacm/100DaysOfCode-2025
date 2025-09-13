#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= V-1; i++) {
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            throw runtime_error("Graph contains a negative weight cycle");
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},
        {3,2,5},{3,1,1},{4,3,-3}
    };

    try {
        vector<int> dist = bellmanFord(V, edges, 0);
        cout << "Shortest Distances: ";
        for (int d : dist) cout << d << " ";
        cout << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
