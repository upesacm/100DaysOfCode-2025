#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, struct Node* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    
    struct QueueNode* temp = queue->front;
    struct Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return treeNode;
}

void freeQueue(struct Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input!\n");
        exit(1);
    }
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    
    printf("Level order traversal: ");
    while (!isQueueEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);
        
        if (current->left) enqueue(queue, current->left);
        if (current->right) enqueue(queue, current->right);
    }
    printf("\n");
    
    freeQueue(queue);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    root = createTree();
    
    levelOrder(root);
    
    freeTree(root);
    return 0;
}
