#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Node for a queue
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node
void enqueue(Queue* q, TreeNode* node) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = node;
    newQueueNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
        return;
    }
    q->rear->next = newQueueNode;
    q->rear = newQueueNode;
}

// Function to dequeue a tree node
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    QueueNode* temp = q->front;
    TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Level Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isQueueEmpty(q)) {
        TreeNode* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
    printf("\n");
    free(q);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root1);

    // Example 2
    TreeNode* root2 = createNode(10);
    root2->right = createNode(20);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root2);

    return 0;
}
