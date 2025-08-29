#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return node;
}

void rightView(struct Node* root) {
    if (root == NULL) return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        int n = q.rear - q.front + 1;
        for (int i = 0; i < n; i++) {
            struct Node* temp = dequeue(&q);
            if (i == n - 1) printf("%d ", temp->data);
            if (temp->left) enqueue(&q, temp->left);
            if (temp->right) enqueue(&q, temp->right);
        }
    }
}

struct Node* buildTree() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct Node* node = newNode(x);
    printf("Enter left child of %d (-1 for no child): ", x);
    node->left = buildTree();
    printf("Enter right child of %d (-1 for no child): ", x);
    node->right = buildTree();
    return node;
}

int main() {
    printf("Enter root value (-1 for no node): ");
    struct Node* root = buildTree();
    printf("Right View of Binary Tree: ");
    rightView(root);
    return 0;
}
