#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;


typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}


void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(q, current->left);
        if (current->right)
            enqueue(q, current->right);
    }

    free(q);
}


int main() {
    
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    printf("Level Order Traversal (Example 1): ");
    levelOrderTraversal(root1);  
    printf("\n");

    
    Node* root2 = createNode(10);
    root2->right = createNode(20);
    printf("Level Order Traversal (Example 2): ");
    levelOrderTraversal(root2);  
    printf("\n");

    
    free(root1->left);
    free(root1->right);
    free(root1);
    free(root2->right);
    free(root2);

    return 0;
}
