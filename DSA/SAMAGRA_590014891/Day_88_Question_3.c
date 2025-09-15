#include <stdio.h>
#include <stdbool.h>

#define V 4
#define MAXQ 100

int adj[V][V];

bool isBipartite(int src) {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = -1;

    int queue[MAXQ], front = 0, rear = 0;
    queue[rear++] = src;
    color[src] = 0;

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

int main() {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][0] = adj[0][3] = 1;

    if (isBipartite(0)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
