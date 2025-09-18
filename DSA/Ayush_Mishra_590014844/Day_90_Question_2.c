#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    int *degree = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) odd++;
    }
    if (odd == 0) printf("Eulerian Circuit Exists\n");
    else if (odd == 2) printf("Eulerian Path Exists\n");
    else printf("No Eulerian Path or Circuit\n");
    free(degree);
    return 0;
}
