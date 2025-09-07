#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph representation using an adjacency list
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode *head[MAX_VERTICES];
    int V;
} Graph;

AdjListNode* new_adj_list_node(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void add_edge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = new_adj_list_node(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
    
    newNode = new_adj_list_node(src);
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

void dfs_util(Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    AdjListNode* temp = graph->head[v];
    while (temp) {
        int neighbor = temp->dest;
        if (!visited[neighbor]) {
            dfs_util(graph, neighbor, visited);
        }
        temp = temp->next;
    }
}

int count_components(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int count = 0;
    
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs_util(graph, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    // Example 1
    Graph* graph1 = (Graph*)malloc(sizeof(Graph));
    graph1->V = 5;
    for (int i = 0; i < 5; i++) graph1->head[i] = NULL;
    add_edge(graph1, 0, 1);
    add_edge(graph1, 1, 2);
    add_edge(graph1, 3, 4);
    printf("Example 1: Number of connected components: %d\n", count_components(graph1));

    // Example 2
    Graph* graph2 = (Graph*)malloc(sizeof(Graph));
    graph2->V = 4;
    for (int i = 0; i < 4; i++) graph2->head[i] = NULL;
    add_edge(graph2, 0, 1);
    add_edge(graph2, 2, 3);
    printf("Example 2: Number of connected components: %d\n", count_components(graph2));
    
    return 0;
}
