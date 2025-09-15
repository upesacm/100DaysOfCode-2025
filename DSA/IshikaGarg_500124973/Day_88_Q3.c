#include <stdio.h>
#include <stdbool.h>

#define V 4  // number of vertices
#define E 4  // number of edges

int adj[V][V];  // adjacency matrix

bool bfsBipartite(int src, int color[]) {
    int queue[V], front = 0, rear = 0;
    queue[rear++] = src;
    color[src] = 1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isBipartite() {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!bfsBipartite(i, color))
                return false;
        }
    }
    return true;
}

int main() {
    // Example 1: Square (bipartite)
    int edges1[E][2] = {{0,1},{1,2},{2,3},{3,0}};
    for (int i=0;i<V;i++) for(int j=0;j<V;j++) adj[i][j]=0;
    for (int i=0;i<E;i++) {
        adj[edges1[i][0]][edges1[i][1]] = 1;
        adj[edges1[i][1]][edges1[i][0]] = 1;
    }

    printf("Graph is bipartite? %s\n", isBipartite() ? "Yes" : "No");

    // Example 2: Triangle (not bipartite)
    int adj2[V][V] = {
        {0,1,1,0},
        {1,0,1,0},
        {1,1,0,0},
        {0,0,0,0}
    };
    for (int i=0;i<V;i++) for(int j=0;j<V;j++) adj[i][j]=adj2[i][j];

    printf("Graph is bipartite? %s\n", isBipartite() ? "Yes" : "No");

    return 0;
}

