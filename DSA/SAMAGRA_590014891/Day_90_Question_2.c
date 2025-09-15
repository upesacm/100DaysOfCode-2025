#include <stdio.h>

#define MAX 20

int V;
int degree[MAX];

int main() {
    int E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (degree[i] % 2 != 0) odd++;
    }
    if (odd == 0) printf("Eulerian Circuit Exists\n");
    else if (odd == 2) printf("Eulerian Path Exists\n");
    else printf("No Eulerian Path or Circuit\n");
    return 0;
}
