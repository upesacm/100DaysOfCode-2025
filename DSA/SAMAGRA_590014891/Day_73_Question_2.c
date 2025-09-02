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

struct Queue {
    struct Node** arr;
    int front, rear, size, cap;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->cap = cap;
    q->arr = (struct Node**)malloc(cap * sizeof(struct Node*));
    q->front = 0; q->rear = -1; q->size = 0;
    return q;
}

int isEmpty(struct Queue* q) { return q->size == 0; }
void enqueue(struct Queue* q, struct Node* node) {
    if (q->size == q->cap) return;
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = node;
    q->size++;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->cap;
    q->size--;
    return node;
}

void levelOrder(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* cur = dequeue(q);
        printf("%d ", cur->data);
        if (cur->left) enqueue(q, cur->left);
        if (cur->right) enqueue(q, cur->right);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    levelOrder(root);
    return 0;
}
