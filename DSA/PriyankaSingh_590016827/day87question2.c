#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int vertices;
    Edge** adjList;
} Graph;

typedef struct PriorityQueueNode {
    int vertex;
    int distance;
} PriorityQueueNode;

typedef struct PriorityQueue {
    PriorityQueueNode nodes[MAX_VERTICES];
    int size;
} PriorityQueue;

Edge* createEdge(int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Edge**)malloc(vertices * sizeof(Edge*));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addWeightedEdge(Graph* graph, int u, int v, int w) {
    Edge* newEdge = createEdge(v, w);
    newEdge->next = graph->adjList[u];
    graph->adjList[u] = newEdge;
}

void swapPQNodes(PriorityQueueNode* a, PriorityQueueNode* b) {
    PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->nodes[left].distance < pq->nodes[smallest].distance) {
        smallest = left;
    }
    if (right < pq->size && pq->nodes[right].distance < pq->nodes[smallest].distance) {
        smallest = right;
    }
    if (smallest != idx) {
        swapPQNodes(&pq->nodes[idx], &pq->nodes[smallest]);
        minHeapify(pq, smallest);
    }
}

PriorityQueueNode extractMin(PriorityQueue* pq) {
    PriorityQueueNode root = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return root;
}

void decreaseKey(PriorityQueue* pq, int vertex, int newDist) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (pq->nodes[i].vertex == vertex) {
            pq->nodes[i].distance = newDist;
            break;
        }
    }
    while (i > 0 && pq->nodes[(i - 1) / 2].distance > pq->nodes[i].distance) {
        swapPQNodes(&pq->nodes[i], &pq->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(Graph* graph, int source) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;

    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    for (int i = 0; i < graph->vertices; i++) {
        pq->nodes[pq->size].vertex = i;
        pq->nodes[pq->size].distance = distances[i];
        pq->size++;
    }
    for (int i = pq->size / 2 - 1; i >= 0; i--) {
        minHeapify(pq, i);
    }

    while (pq->size > 0) {
        PriorityQueueNode minNode = extractMin(pq);
        int u = minNode.vertex;

        Edge* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            int weight = temp->weight;
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                decreaseKey(pq, v, distances[v]);
            }
            temp = temp->next;
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
    free(pq);
}

int main() {
    printf("Example 1: Dijkstra's Algorithm\n");
    int vertices1 = 5;
    Graph* graph1 = createGraph(vertices1);
    addWeightedEdge(graph1, 0, 1, 2);
    addWeightedEdge(graph1, 0, 2, 4);
    addWeightedEdge(graph1, 1, 2, 1);
    addWeightedEdge(graph1, 2, 3, 7);
    addWeightedEdge(graph1, 1, 4, 3);
    dijkstra(graph1, 0);
    printf("\n");

    printf("Example 2: Dijkstra's Algorithm\n");
    int vertices2 = 3;
    Graph* graph2 = createGraph(vertices2);
    addWeightedEdge(graph2, 0, 1, 5);
    addWeightedEdge(graph2, 1, 2, 2);
    dijkstra(graph2, 0);

    return 0;
}
