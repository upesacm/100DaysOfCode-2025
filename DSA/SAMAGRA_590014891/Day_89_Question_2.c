#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node { int v, w; struct Node* next; };
struct Node* adj[100];
int V;

void addEdge(int u, int v, int w) {
    struct Node* n1 = malloc(sizeof(struct Node));
    n1->v = v; n1->w = w; n1->next = adj[u]; adj[u] = n1;
    struct Node* n2 = malloc(sizeof(struct Node));
    n2->v = u; n2->w = w; n2->next = adj[v]; adj[v] = n2;
}

int prim() {
    int key[100], inMST[100], res = 0;
    for (int i = 0; i < V; i++) key[i] = INT_MAX, inMST[i] = 0;
    key[0] = 0;
    for (int c = 0; c < V; c++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        inMST[u] = 1; res += key[u];
        for (struct Node* p = adj[u]; p; p = p->next)
            if (!inMST[p->v] && p->w < key[p->v]) key[p->v] = p->w;
    }
    return res;
}

int main() {
    V = 5;
    addEdge(0,1,2); addEdge(0,3,6);
    addEdge(1,2,3); addEdge(1,3,8); addEdge(1,4,5);
    addEdge(2,4,7); addEdge(3,4,9);
    printf("%d\n", prim());
    return 0;
}
