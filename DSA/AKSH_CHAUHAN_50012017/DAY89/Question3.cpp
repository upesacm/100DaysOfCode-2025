#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& adjT, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adjT[u]) {
        if (!visited[v]) dfs2(v, adjT, visited);
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs1(i, adj, visited, st);
    }

    vector<vector<int>> adjT(V);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            adjT[v].push_back(u);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            dfs2(u, adjT, visited);
            sccCount++;
        }
    }
    return sccCount;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    cout << "SCC Count (Kosaraju): " << kosaraju(V, adj) << endl;
    return 0;
}
