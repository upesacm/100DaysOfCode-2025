#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QueueNode arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct List {
    int data;
    struct List* next;
};

struct Map {
    int hd;
    struct List* nodes;
    struct Map* next;
};

struct Map* addToMap(struct Map* map, int hd, int data) {
    struct Map* temp = map;
    while (temp) {
        if (temp->hd == hd) {
            struct List* newnode = (struct List*)malloc(sizeof(struct List));
            newnode->data = data;
            newnode->next = NULL;
            struct List* t = temp->nodes;
            while (t->next) t = t->next;
            t->next = newnode;
            return map;
        }
        temp = temp->next;
    }
    struct Map* newmap = (struct Map*)malloc(sizeof(struct Map));
    newmap->hd = hd;
    newmap->nodes = (struct List*)malloc(sizeof(struct List));
    newmap->nodes->data = data;
    newmap->nodes->next = NULL;
    newmap->next = map;
    return newmap;
}

void verticalOrder(struct Node* root) {
    if (!root) return;
    struct Queue q;
    q.front = q.rear = 0;
    enqueue(&q, root, 0);
    struct Map* map = NULL;
    while (!isEmpty(&q)) {
        struct QueueNode temp = dequeue(&q);
        map = addToMap(map, temp.hd, temp.node->data);
        if (temp.node->left) enqueue(&q, temp.node->left, temp.hd - 1);
        if (temp.node->right) enqueue(&q, temp.node->right, temp.hd + 1);
    }
    int min = 1000, max = -1000;
    struct Map* t = map;
    while (t) {
        if (t->hd < min) min = t->hd;
        if (t->hd > max) max = t->hd;
        t = t->next;
    }
    for (int i = min; i <= max; i++) {
        printf("[");
        struct Map* m = map;
        int first = 1;
        while (m) {
            if (m->hd == i) {
                struct List* l = m->nodes;
                while (l) {
                    if (!first) printf(",");
                    printf("%d", l->data);
                    first = 0;
                    l = l->next;
                }
            }
            m = m->next;
        }
        printf("]");
        if (i != max) printf(" ");
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Vertical Order Traversal:\n");
    verticalOrder(root);
    return 0;
}
