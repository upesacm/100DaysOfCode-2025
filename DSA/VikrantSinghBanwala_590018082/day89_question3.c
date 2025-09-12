#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

void addEdge(Node **graph, int u, int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs1(Node **graph, int u, int *visited, int *stack, int *top) {
    visited[u] = 1;
    for (Node *cur = graph[u]; cur != NULL; cur = cur->next) {
        if (!visited[cur->v]) dfs1(graph, cur->v, visited, stack, top);
    }
    stack[(*top)++] = u;
}

void dfs2(Node **transpose, int u, int *visited) {
    visited[u] = 1;
    for (Node *cur = transpose[u]; cur != NULL; cur = cur->next) {
        if (!visited[cur->v]) dfs2(transpose, cur->v, visited);
    }
}

int kosaraju(int V, int E, int edges[][2]) {
    Node **graph = (Node**)calloc(V, sizeof(Node*));
    Node **transpose = (Node**)calloc(V, sizeof(Node*));
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        addEdge(graph, u, v);
        addEdge(transpose, v, u);
    }
    int *visited = (int*)calloc(V, sizeof(int));
    int *stack = (int*)malloc(V * sizeof(int));
    int top = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs1(graph, i, visited, stack, &top);
    }
    for (int i = 0; i < V; i++) visited[i] = 0;
    int scc_count = 0;
    for (int i = top - 1; i >= 0; i--) {
        int u = stack[i];
        if (!visited[u]) {
            dfs2(transpose, u, visited);
            scc_count++;
        }
    }
    for (int i = 0; i < V; i++) {
        Node *cur = graph[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        cur = transpose[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(graph);
    free(transpose);
    free(visited);
    free(stack);
    return scc_count;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    int edges[E][2];
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    printf("%d\n", kosaraju(V, E, edges));
    return 0;
}
