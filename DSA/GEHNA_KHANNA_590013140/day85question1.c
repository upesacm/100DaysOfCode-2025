#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX];

void bfs(int start, int n) {
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int v, e, u, w;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = adj[w][u] = 1;
    }

    bfs(0, v);
    return 0;
}
