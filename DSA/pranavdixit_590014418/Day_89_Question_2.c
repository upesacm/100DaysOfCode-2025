#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX];
int key[MAX];
int parent[MAX];
int visited[MAX];

int minKey(int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int prim(int V) {
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !visited[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    int mstWeight = 0;
    for (int i = 1; i < V; i++) mstWeight += adj[i][parent[i]];
    return mstWeight;
}

int main() {
    int V = 5;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    adj[0][1] = 2; adj[0][3] = 6;
    adj[1][0] = 2; adj[1][2] = 3; adj[1][3] = 8; adj[1][4] = 5;
    adj[2][1] = 3; adj[2][4] = 7;
    adj[3][0] = 6; adj[3][1] = 8; adj[3][4] = 9;
    adj[4][1] = 5; adj[4][2] = 7; adj[4][3] = 9;

    printf("MST Weight (Prim): %d\n", prim(V));
    return 0;
}
