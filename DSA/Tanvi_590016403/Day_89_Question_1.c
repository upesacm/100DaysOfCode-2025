#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

// -------------------- Union-Find (for Kruskal) --------------------
int parent[1000], rankArr[1000];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankArr[u] < rankArr[v]) parent[u] = v;
        else if (rankArr[u] > rankArr[v]) parent[v] = u;
        else { parent[v] = u; rankArr[u]++; }
    }
}

// -------------------- Kruskal’s Algorithm --------------------
typedef struct {
    int u, v, w;
} Edge;

int cmpEdges(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int kruskalMST(Edge edges[], int V, int E) {
    makeSet(V);
    qsort(edges, E, sizeof(Edge), cmpEdges);

    int cost = 0, count = 0;
    for (int i = 0; i < E && count < V-1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            cost += edges[i].w;
            unionSets(edges[i].u, edges[i].v);
            count++;
        }
    }
    return cost;
}

// -------------------- Prim’s Algorithm --------------------
typedef struct {
    int v, w;
} Adj;

typedef struct {
    int u, v, w;
} PQItem;

PQItem pq[10000];
int pqSize;

void push(int u, int v, int w) {
    pq[pqSize].u = u; pq[pqSize].v = v; pq[pqSize].w = w;
    int i = pqSize++;
    while (i > 0 && pq[(i-1)/2].w > pq[i].w) {
        PQItem tmp = pq[i]; pq[i] = pq[(i-1)/2]; pq[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

PQItem pop() {
    PQItem root = pq[0];
    pq[0] = pq[--pqSize];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < pqSize && pq[l].w < pq[smallest].w) smallest = l;
        if (r < pqSize && pq[r].w < pq[smallest].w) smallest = r;
        if (smallest == i) break;
        PQItem tmp = pq[i]; pq[i] = pq[smallest]; pq[smallest] = tmp;
        i = smallest;
    }
    return root;
}

int primMST(int V, int adj[100][100]) {
    int visited[100] = {0}, cost = 0, count = 0;
    pqSize = 0;

    visited[0] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[0][v]) push(0, v, adj[0][v]);
    }

    while (pqSize > 0 && count < V-1) {
        PQItem e = pop();
        if (visited[e.v]) continue;
        visited[e.v] = 1;
        cost += e.w;
        count++;

        for (int v = 0; v < V; v++) {
            if (adj[e.v][v] && !visited[v]) {
                push(e.v, v, adj[e.v][v]);
            }
        }
    }
    return cost;
}

// -------------------- Kosaraju’s Algorithm --------------------
int adjDir[100][100], adjRev[100][100];
int visited[100], order[100], idx;
int Vdir;

void dfs1(int u) {
    visited[u] = 1;
    for (int v = 0; v < Vdir; v++) {
        if (adjDir[u][v] && !visited[v]) dfs1(v);
    }
    order[idx++] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    for (int v = 0; v < Vdir; v++) {
        if (adjRev[u][v] && !visited[v]) dfs2(v);
    }
}

int kosarajuSCC(int V) {
    Vdir = V;
    memset(visited, 0, sizeof(visited));
    idx = 0;

    for (int i = 0; i < V; i++) if (!visited[i]) dfs1(i);

    memset(visited, 0, sizeof(visited));
    int sccCount = 0;

    for (int i = idx-1; i >= 0; i--) {
        int u = order[i];
        if (!visited[u]) {
            dfs2(u);
            sccCount++;
        }
    }
    return sccCount;
}

// -------------------- Main --------------------
int main() {
    // Example 1: Kruskal
    printf("=== Kruskal Example ===\n");
    int V1 = 4, E1 = 5;
    Edge edges1[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    printf("MST Cost (Kruskal): %d\n", kruskalMST(edges1, V1, E1));

    // Example 2: Prim
    printf("\n=== Prim Example ===\n");
    int V2 = 5;
    int adj2[100][100] = {0};
    adj2[0][1]=2; adj2[0][3]=6;
    adj2[1][0]=2; adj2[1][2]=3; adj2[1][3]=8; adj2[1][4]=5;
    adj2[2][1]=3; adj2[2][4]=7;
    adj2[3][0]=6; adj2[3][1]=8; adj2[3][4]=9;
    adj2[4][1]=5; adj2[4][2]=7; adj2[3][4]=9;
    printf("MST Cost (Prim): %d\n", primMST(V2, adj2));

    // Example 3: Kosaraju
    printf("\n=== Kosaraju Example ===\n");
    int V3 = 5, E3 = 5;
    int edges3[][2] = {{1,0},{0,2},{2,1},{0,3},{3,4}};
    memset(adjDir, 0, sizeof(adjDir));
    memset(adjRev, 0, sizeof(adjRev));
    for (int i=0; i<E3; i++) {
        int u=edges3[i][0], v=edges3[i][1];
        adjDir[u][v]=1;
        adjRev[v][u]=1;
    }
    printf("SCC Count (Kosaraju): %d\n", kosarajuSCC(V3));

    return 0;
}
