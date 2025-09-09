#include <vector>
#include <functional>
#include <algorithm>
#include <cstddef>

using namespace std;

// DFS-based topological sort using finish-time ordering.
// Input: n = number of vertices, edges = list of directed edges (pairs {u,v}).
// Output: vector<int> containing vertices in topological order.
vector<int> topologicalSortDFS(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return {};
    
    // Build adjacency list for directed graph
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
        }
    }
    
    vector<int> result;
    vector<bool> visited(n, false);
    
    // DFS with finish-time ordering (post-order)
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        // Add to result when finishing (post-order)
        result.push_back(u);
    };
    
    // Visit all unvisited vertices
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    // Reverse to get topological order (finish times in reverse)
    reverse(result.begin(), result.end());
    return result;
}

// Alternative implementation using explicit stack (iterative DFS)
vector<int> topologicalSortIterative(int n, const vector<pair<int,int>>& edges) {
    if (n <= 0) return {};
    
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
        }
    }
    
    vector<int> result;
    vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=finished
    
    for (int start = 0; start < n; ++start) {
        if (state[start] != 0) continue;
        
        vector<int> stack;
        stack.push_back(start);
        
        while (!stack.empty()) {
            int u = stack.back();
            
            if (state[u] == 0) {
                state[u] = 1; // Mark as visiting
                for (int v : adj[u]) {
                    if (state[v] == 0) {
                        stack.push_back(v);
                    }
                }
            } else {
                stack.pop_back();
                if (state[u] == 1) {
                    state[u] = 2; // Mark as finished
                    result.push_back(u);
                }
            }
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Default wrapper function
vector<int> topologicalSort(int n, const vector<pair<int,int>>& edges) {
    return topologicalSortDFS(n, edges);
}
