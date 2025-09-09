#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsTopo(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) dfsTopo(neigh, adj, visited, st);
    }
    st.push(node); 
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfsTopo(i, adj, visited, st);
    }
    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = {2,0};
    adj[4] = {0,1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topoSort(V, adj);

    cout << "Topological Order: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    return 0;
}
