#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* ================= Problem 1 =================
   Sum of All Nodes (Recursive Accumulation) */
int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

/* ================= Problem 2 =================
   Level Order Traversal (using Queue) */

// Queue structure for BFS
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Check empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return; // queue full
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return node;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left != NULL) enqueue(&q, curr->left);
        if (curr->right != NULL) enqueue(&q, curr->right);
    }
    printf("\n");
}

/* ================= Problem 3 =================
   Find Max in Binary Tree (Recursive Comparison) */
int findMax(struct Node* root) {
    if (root == NULL) return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

/* Utility function: Inorder Traversal (for display) */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* ================= Main Function ================= */
int main() {
    // Create a sample tree
    //        10
