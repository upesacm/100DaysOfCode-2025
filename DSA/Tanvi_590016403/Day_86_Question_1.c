#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ------------------------------
// Graph structure
// ------------------------------
typedef struct {
    int V;          // number of vertices
    int **adj;      // adjacency matrix
} Graph;

// Create a graph
Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int*)calloc(V, sizeof(int));
    }
    return g;
}

// Add edge (undirected)
void addEdgeUndirected(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

// Add edge (directed)
void addEdgeDirected(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
}

// ------------------------------
// 1. Cycle Detection in Undirected Graph (DFS with parent tracking)
// ------------------------------
bool dfsUndirected(Graph* g, int v, bool visited[], int parent) {
    visited[v] = true;
    for (int u = 0; u < g->V; u++) {
        if (g->adj[v][u]) {
            if (!visited[u]) {
                if (dfsUndirected(g, u, visited, v))
                    return true;
            } else if (u != parent) {
                return true;  // found a cycle
            }
        }
    }
    return false;
}

bool hasCycleUndirected(Graph* g) {
    bool visited[g->V];
    for (int i = 0; i < g->V; i++) visited[i] = false;

    for (int v = 0; v < g->V; v++) {
        if (!visited[v]) {
            if (dfsUndirected(g, v, visited, -1))
                return true;
        }
    }
    return false;
}

// ------------------------------
// 2. Cycle Detection in Directed Graph (DFS with recursion stack)
// ------------------------------
bool dfsDirected(Graph* g, int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int u = 0; u < g->V; u++) {
        if (g->adj[v][u]) {
            if (!visited[u] && dfsDirected(g, u, visited, recStack))
                return true;
            else if (recStack[u])
                return true;  // cycle detected
        }
    }
    recStack[v] = false;
    return false;
}

bool hasCycleDirected(Graph* g) {
    bool visited[g->V], recStack[g->V];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int v = 0; v < g->V; v++) {
        if (!visited[v]) {
            if (dfsDirected(g, v, visited, recStack))
                return true;
        }
    }
    return false;
}

// ------------------------------
// 3. Topological Sort using DFS
// ------------------------------
void dfsTopo(Graph* g, int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    for (int u = 0; u < g->V; u++) {
        if (g->adj[v][u] && !visited[u]) {
            dfsTopo(g, u, visited, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void topologicalSort(Graph* g) {
    bool visited[g->V];
    int stack[g->V];
    int top = 0;

    for (int i = 0; i < g->V; i++) visited[i] = false;

    for (int v = 0; v < g->V; v++) {
        if (!visited[v]) {
            dfsTopo(g, v, visited, stack, &top);
        }
    }

    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// ------------------------------
// Main
// ------------------------------
int main() {
    // ---------- Example 1: Undirected Cycle Detection ----------
    printf("Undirected Graph Cycle Detection:\n");
    Graph* g1 = createGraph(3);
    addEdgeUndirected(g1, 0, 1);
    addEdgeUndirected(g1, 1, 2);
    addEdgeUndirected(g1, 2, 0);
    if (hasCycleUndirected(g1))
        printf("Yes\n");
    else
        printf("No\n");

    // ---------- Example 2: Directed Cycle Detection ----------
    printf("\nDirected Graph Cycle Detection:\n");
    Graph* g2 = createGraph(3);
    addEdgeDirected(g2, 0, 1);
    addEdgeDirected(g2, 1, 2);
    addEdgeDirected(g2, 2, 0);
    if (hasCycleDirected(g2))
        printf("Yes\n");
    else
        printf("No\n");

    // ---------- Example 3: Topological Sort ----------
    printf("\nTopological Sort:\n");
    Graph* g3 = createGraph(6);
    addEdgeDirected(g3, 5, 2);
    addEdgeDirected(g3, 5, 0);
    addEdgeDirected(g3, 4, 0);
    addEdgeDirected(g3, 4, 1);
    addEdgeDirected(g3, 2, 3);
    addEdgeDirected(g3, 3, 1);
    topologicalSort(g3);

    return 0;
}
