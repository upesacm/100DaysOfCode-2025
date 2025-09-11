#include <iostream>
#include <vector>
using namespace std;

void dfsComponent(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfsComponent(neigh, adj, visited);
        }
    }
}

int countComponents(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsComponent(i, adj, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {3};
    cout << "Connected Components: " << countComponents(V, adj) << endl;
    return 0;
}
