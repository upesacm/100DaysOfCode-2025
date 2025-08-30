#include <stdio.h>
#include <stdlib.h>

// ------------------ Node Structure ------------------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ------------------ Create New Node ------------------
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// ------------------ Queue for Level Order ------------------
struct QueueNode {
    struct Node* node;
    int level;
};
struct Queue {
    struct QueueNode arr[100];
    int front, rear;
};
void enqueue(struct Queue* q, struct Node* node, int level) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].level = level;
    q->rear++;
}
struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// ------------------ 1. Left View ------------------
void leftView(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    q.front = q.rear = 0;
    enqueue(&q, root, 0);

    int maxLevel = -1;

    while (!isEmpty(&q)) {
        struct QueueNode temp = dequeue(&q);
        struct Node* node = temp.node;
        int level = temp.level;

        if (level > maxLevel) {
            printf("%d ", node->data);  // first node at this level
            maxLevel = level;
        }

        if (node->left) enqueue(&q, node->left, level + 1);
        if (node->right) enqueue(&q, node->right, level + 1);
    }
    printf("\n");
}

// ------------------ 2. Right View ------------------
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    q.front = q.rear = 0;
    enqueue(&q, root, 0);

    int lastPrintedLevel = -1;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        for (int i = 0; i < size; i++) {
            struct QueueNode temp = dequeue(&q);
            struct Node* node = temp.node;
            int level = temp.level;

            if (i == size - 1) {  // last node at this level
                printf("%d ", node->data);
                lastPrintedLevel = level;
            }

            if (node->left) enqueue(&q, node->left, level + 1);
            if (node->right) enqueue(&q, node->right, level + 1);
        }
    }
    printf("\n");
}

// ------------------ 3. Diameter of Binary Tree ------------------
int max(int a, int b) { return (a > b) ? a : b; }

int diameterUtil(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldiameter = diameterUtil(root->left, &lh);
    int rdiameter = diameterUtil(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int diameter(struct Node* root) {
    int height = 0;
    return diameterUtil(root, &height);
}

// ------------------ Main ------------------
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // 1. Left View
    printf("Left View: ");
    leftView(root);

    // 2. Right View
    printf("Right View: ");
    rightView(root);

    // 3. Diameter
    printf("Diameter of tree = %d\n", diameter(root));

    return 0;
}
