#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfsUtil(neigh, adj, visited);
        }
    }
}
void dfs(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    dfsUtil(0, adj, visited);
}
int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};
    cout << "DFS Traversal: ";
    dfs(V, adj);
    cout << endl;
    return 0;
}
