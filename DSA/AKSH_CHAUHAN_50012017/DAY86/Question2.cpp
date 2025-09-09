#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neigh : adj[node]) {
        if (!visited[neigh] && dfsDirected(neigh, adj, visited, recStack))
            return true;
        else if (recStack[neigh])
            return true; 
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false), recStack(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsDirected(i, adj, visited, recStack)) return true;
        }
    }
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};

    cout << "Cycle in directed graph? "
         << (hasCycleDirected(V, adj) ? "Yes" : "No") << endl;

    return 0;
}
