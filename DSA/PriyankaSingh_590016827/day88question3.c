#include <stdlib.h>
#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) color[i] = 0; // 0=uncolored, 1, -1

    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int start = 0; start < graphSize; start++) {
        if (color[start] != 0) continue;

        int front = 0, back = 0;
        queue[back++] = start;
        color[start] = 1;

        while (front < back) {
            int node = queue[front++];
            for (int j = 0; j < graphColSize[node]; j++) {
                int nei = graph[node][j];
                if (color[nei] == 0) {
                    color[nei] = -color[node];
                    queue[back++] = nei;
                } else if (color[nei] == color[node]) {
                    free(queue); free(color);
                    return false;
                }
            }
        }
    }

    free(queue); free(color);
    return true;
}
