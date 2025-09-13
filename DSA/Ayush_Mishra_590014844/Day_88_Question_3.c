#include <stdio.h>
#include <stdlib.h>

#define MAX 99

int adj[MAX][MAX];
int color[MAX];
int queue[MAX];
int front, rear;
int n, e;

int bfs(int start) {
    front = rear = 0;
    queue[rear++] = start;
    color[start] = 1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            if (!bfs(i)) {
                printf("No\n");
                return 0;
            }
    printf("Yes\n");
    return 0;
}
