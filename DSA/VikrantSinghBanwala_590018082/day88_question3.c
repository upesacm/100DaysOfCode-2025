#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node** createGraph(int vertices) {
    Node** graph = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) graph[i] = NULL;
    return graph;
}

void addEdge(Node** graph, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = graph[u];
    graph[u] = node;
    node = (Node*)malloc(sizeof(Node));
    node->vertex = u;
    node->next = graph[v];
    graph[v] = node;
}

int isBipartite(Node** graph, int vertices) {
    int* color = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) color[i] = 0;
    int* queue = (int*)malloc(vertices * sizeof(int));
    for (int start = 0; start < vertices; start++) {
        if (color[start] != 0) continue;
        color[start] = 1;
        int front = 0, rear = 0;
        queue[rear++] = start;
        while (front < rear) {
            int u = queue[front++];
            for (Node* cur = graph[u]; cur != NULL; cur = cur->next) {
                int v = cur->vertex;
                if (color[v] == 0) {
                    color[v] = -color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    free(color);
                    free(queue);
                    return 0;
                }
            }
        }
    }
    free(color);
    free(queue);
    return 1;
}