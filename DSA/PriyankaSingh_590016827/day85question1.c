#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue implementation for BFS
#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool is_empty(Queue *q) {
    return q->rear == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (is_empty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Graph representation using an adjacency list
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode *head[MAX_VERTICES];
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

void bfs(Graph* graph, int start_node, int num_vertices) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    init_queue(&q);

    visited[start_node] = true;
    enqueue(&q, start_node);

    while (!is_empty(&q)) {
        int current_node = dequeue(&q);
        printf("%d ", current_node);

        AdjListNode* temp = graph->head[current_node];
        while (temp) {
            int neighbor = temp->dest;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(&q, neighbor);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    // Example 1
    Graph* graph1 = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < 5; i++) graph1->head[i] = NULL;
    add_edge(graph1, 0, 1);
    add_edge(graph1, 0, 2);
    add_edge(graph1, 1, 3);
    add_edge(graph1, 2, 4);
    printf("Example 1 BFS Traversal: ");
    bfs(graph1, 0, 5);

    // Example 2
    Graph* graph2 = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < 4; i++) graph2->head[i] = NULL;
    add_edge(graph2, 0, 1);
    add_edge(graph2, 1, 2);
    add_edge(graph2, 2, 3);
    printf("Example 2 BFS Traversal: ");
    bfs(graph2, 0, 4);

    return 0;
}
