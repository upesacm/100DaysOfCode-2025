#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();

                for (int neigh : adj[node]) {
                    if (color[neigh] == -1) {
                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    } else if (color[neigh] == color[node]) {
                        return false; // odd cycle
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1,3};
    adj[1] = {0,2};
    adj[2] = {1,3};
    adj[3] = {0,2};

    cout << "Is Bipartite? " << (isBipartite(V, adj) ? "Yes" : "No") << endl;
    return 0;
}
