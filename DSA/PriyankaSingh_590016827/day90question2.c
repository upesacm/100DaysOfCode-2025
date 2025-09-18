#include <stdio.h>

void checkEulerian(int V, int** graph, int* gSize) {
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (gSize[i] % 2 != 0) odd++;
    }

    if (odd == 0)
        printf("Eulerian Circuit Exists\n");
    else if (odd == 2)
        printf("Eulerian Path Exists\n");
    else
        printf("No Eulerian Path or Circuit\n");
}
