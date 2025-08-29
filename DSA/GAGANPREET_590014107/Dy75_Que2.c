#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void printRightView(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        int levelSize = 0;
        QueueNode* temp = q->front;
        while (temp) {
            levelSize++;
            temp = temp->next;
        }
        Node* lastNode = NULL;
        for (int i = 0; i < levelSize; i++) {
            Node* curr = dequeue(q);
            lastNode = curr;
            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }
        if (lastNode) printf("%d ", lastNode->data);
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    printRightView(root);
    return 0;
}
