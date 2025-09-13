#include <iostream>
#include <vector>
using namespace std;

string eulerianPathOrCircuit(int V, vector<vector<int>>& adj) {
    vector<int> degree(V, 0);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            degree[u]++;
        }
    }

    int odd = 0;
    for (int d : degree) if (d % 2 == 1) odd++;

    if (odd == 0) return "Eulerian Circuit Exists";
    else if (odd == 2) return "Eulerian Path Exists";
    else return "No Eulerian Path or Circuit";
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1,2,3};
    adj[1] = {0,2};
    adj[2] = {0,1};
    adj[3] = {0};

    cout << eulerianPathOrCircuit(V, adj) << endl;
    return 0;
}
