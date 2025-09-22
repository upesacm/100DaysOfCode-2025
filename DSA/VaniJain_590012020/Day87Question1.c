#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct 
{
    int items[MAX];
    int front, rear;
} Queue;
void initQueue(Queue* q) 
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q) 
{
    return q->front == -1;
}
void enqueue(Queue* q, int value) 
{
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}
int dequeue(Queue* q) 
{
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) 
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->front++;
    }
    return item;
}
void bfsShortestPath(int n, int graph[MAX][MAX], int src) 
{
    int distance[MAX];
    for (int i = 0; i < n; i++) distance[i] = -1; 
    Queue q;
    initQueue(&q);
    distance[src] = 0;
    enqueue(&q, src);
    while (!isEmpty(&q)) 
    {
        int u = dequeue(&q);
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] == 1 && distance[v] == -1) 
            { 
                distance[v] = distance[u] + 1;
                enqueue(&q, v);
            }
        }
    }

    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) 
    {
        printf("Node %d -> Distance = %d\n", i, distance[i]);
    }
}

int main() 
{
    int n, e;
    int graph[MAX][MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v) [0-indexed]:\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    bfsShortestPath(n, graph, src);
    return 0;
}
