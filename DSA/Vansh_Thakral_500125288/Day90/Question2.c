#include <stdio.h>

#define MAX 20

int V;
int degree[MAX];

void addEdge(int u, int v) {
    degree[u]++;
    degree[v]++;
}

void checkEulerian() {
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (degree[i] % 2 != 0) odd++;

    if (odd == 0)
        printf("Eulerian Circuit Exists\n");
    else if (odd == 2)
        printf("Eulerian Path Exists\n");
    else
        printf("No Eulerian Path or Circuit\n");
}

int main() {
    V = 4;
    int edges[4][2] = {{0,1},{1,2},{2,0},{0,3}};
    for (int i = 0; i < V; i++) degree[i] = 0;

    for (int i = 0; i < 4; i++)
        addEdge(edges[i][0], edges[i][1]);

    checkEulerian(); // Output: Eulerian Path Exists
    return 0;
}
