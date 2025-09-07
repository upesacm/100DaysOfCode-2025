#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (q->rear == NULL) q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

struct QNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

struct List {
    int hd;
    int data;
    struct List* next;
};

void addToList(struct List** head, int hd, int data) {
    struct List* temp = (struct List*)malloc(sizeof(struct List));
    temp->hd = hd;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root, 0);

    struct List* list = NULL;
    int minHd = INT_MAX, maxHd = INT_MIN;

    while (q->front != NULL) {
        struct QNode* qn = dequeue(q);
        struct Node* node = qn->node;
        int hd = qn->hd;
        free(qn);

        addToList(&list, hd, node->data);

        if (hd < minHd) minHd = hd;
        if (hd > maxHd) maxHd = hd;

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
    }

    for (int i = minHd; i <= maxHd; i++) {
        struct List* cur = list;
        while (cur != NULL) {
            if (cur->hd == i)
                printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
