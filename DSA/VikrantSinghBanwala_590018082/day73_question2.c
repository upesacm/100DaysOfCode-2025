#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
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

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Node* treeNode) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newQueueNode;
        queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    struct Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    while (queue->front != NULL) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->value);
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    free(queue);
}

int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    
    levelOrderTraversal(root1);
    printf("\n");

    struct Node* root2 = createNode(10);
    root2->right = createNode(20);
    
    levelOrderTraversal(root2);
    printf("\n");

    return 0;
}
