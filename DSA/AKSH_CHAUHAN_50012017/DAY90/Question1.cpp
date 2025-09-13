#include <iostream>
#include <vector>
using namespace std;

bool backtrack(int node, int visitedCount, vector<vector<int>>& adj, vector<bool>& visited, int V) {
    if (visitedCount == V) return true;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            visited[neigh] = true;
            if (backtrack(neigh, visitedCount + 1, adj, visited, V)) return true;
            visited[neigh] = false; 
        }
    }
    return false;
}

bool hasHamiltonianPath(int V, vector<vector<int>>& adj) {
    for (int start = 0; start < V; start++) {
        vector<bool> visited(V, false);
        visited[start] = true;
        if (backtrack(start, 1, adj, visited, V)) return true;
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1,3};
    adj[1] = {0,2};
    adj[2] = {1,3};
    adj[3] = {2,0};

    cout << "Hamiltonian Path? " << (hasHamiltonianPath(V, adj) ? "Yes" : "No") << endl;
    return 0;
}
