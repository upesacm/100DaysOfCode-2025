#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int vertices;
    int edgesCount;
    Edge* edgeList;
} Graph;

Graph* createGraph(int vertices, int edgesCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edgesCount = edgesCount;
    graph->edgeList = (Edge*)malloc(edgesCount * sizeof(Edge));
    return graph;
}

void bellmanFord(Graph* graph, int source) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;

    for (int i = 0; i < graph->vertices - 1; i++) {
        for (int j = 0; j < graph->edgesCount; j++) {
            int u = graph->edgeList[j].src;
            int v = graph->edgeList[j].dest;
            int weight = graph->edgeList[j].weight;
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    for (int j = 0; j < graph->edgesCount; j++) {
        int u = graph->edgeList[j].src;
        int v = graph->edgeList[j].dest;
        int weight = graph->edgeList[j].weight;
        if (distances[u] != INF && distances[u] + weight < distances[v]) {
            printf("Graph contains a negative weight cycle!\n");
            free(distances);
            return;
        }
    }

    printf("Output: [");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d", distances[i]);
        if (i < graph->vertices - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(distances);
}

int main() {
    printf("Example 1: Bellman-Ford Algorithm\n");
    int vertices1 = 5, edges1 = 8;
    Graph* graph1 = createGraph(vertices1, edges1);
    graph1->edgeList[0] = (Edge){0, 1, -1};
    graph1->edgeList[1] = (Edge){0, 2, 4};
    graph1->edgeList[2] = (Edge){1, 2, 3};
    graph1->edgeList[3] = (Edge){1, 3, 2};
    graph1->edgeList[4] = (Edge){1, 4, 2};
    graph1->edgeList[5] = (Edge){3, 2, 5};
    graph1->edgeList[6] = (Edge){3, 1, 1};
    graph1->edgeList[7] = (Edge){4, 3, -3};
    bellmanFord(graph1, 0);
    printf("\n");

    printf("Example 2: Bellman-Ford Algorithm\n");
    int vertices2 = 3, edges2 = 2;
    Graph* graph2 = createGraph(vertices2, edges2);
    graph2->edgeList[0] = (Edge){0, 1, 5};
    graph2->edgeList[1] = (Edge){1, 2, -2};
    bellmanFord(graph2, 0);

    return 0;
}
