#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};
    cout << "BFS Traversal: ";
    bfs(V, adj);
    cout << endl;
    return 0;
}
