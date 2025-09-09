#include <iostream>
#include <vector>
using namespace std;

bool dfsUndirected(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfsUndirected(neigh, node, adj, visited)) return true;
        } else if (neigh != parent) {
            return true; 
        }
    }
    return false;
}

bool hasCycleUndirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsUndirected(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);
    adj[0] = {1,2};
    adj[1] = {0,2};
    adj[2] = {0,1};

    cout << "Cycle in undirected graph? " 
         << (hasCycleUndirected(V, adj) ? "Yes" : "No") << endl;

    return 0;
}
