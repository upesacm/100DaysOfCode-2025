#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue 
{
    int items[MAX];
    int front, rear;
};
void initQueue(struct Queue* q) 
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct Queue* q) 
{
    return q->front == -1;
}
void enqueue(struct Queue* q, int value) 
{
    if (q->rear == MAX - 1) 
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}
void BFS(int n, int adj[n][n], int start) 
{
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, start);
    visited[start] = 1;
    printf("BFS traversal starting from node %d: ", start);
    while (!isEmpty(&q)) 
    {
        int node = dequeue(&q);
        printf("%d ", node);
        for (int i = 0; i < n; i++) 
        {
            if (adj[node][i] && !visited[i]) 
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() 
{
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Enter edges (u v) format:\n");
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    BFS(n, adj, 0);
    return 0;
}
