#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPathUnweighted(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (dist[neigh] == -1) {
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }
    return dist;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2,5};
    adj[5] = {4};

    vector<int> dist = shortestPathUnweighted(V, adj, 0);

    cout << "Distances: ";
    for (int d : dist) cout << d << " ";
    cout << endl;

    return 0;
}
