#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QueueNode {
    Node *node;
    int hd;
} QueueNode;

typedef struct Queue {
    QueueNode data[MAX];
    int front, rear;
} Queue;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void enqueue(Queue* q, Node* node, int hd) {
    q->data[q->rear].node = node;
    q->data[q->rear].hd = hd;
    q->rear++;
}

QueueNode dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void verticalOrder(Node* root) {
    Queue q = {.front = 0, .rear = 0};
    int hdMap[MAX][MAX], count[MAX] = {0};
    int minHd = MAX, maxHd = -MAX;

    enqueue(&q, root, MAX / 2);

    while (!isEmpty(&q)) {
        QueueNode temp = dequeue(&q);
        int hd = temp.hd;
        Node* node = temp.node;

        hdMap[hd][count[hd]++] = node->data;
        if (hd < minHd) minHd = hd;
        if (hd > maxHd) maxHd = hd;

        if (node->left) enqueue(&q, node->left, hd - 1);
        if (node->right) enqueue(&q, node->right, hd + 1);
    }

    for (int i = minHd; i <= maxHd; i++) {
        printf("[");
        for (int j = 0; j < count[i]; j++) {
            printf("%d", hdMap[i][j]);
            if (j < count[i] - 1) printf(",");
        }
        printf("] ");
    }
    printf("\n");
}

int main() {
    int n, val;
    Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    verticalOrder(root);
    return 0;
}
