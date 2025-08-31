#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node** array;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

void leftView(struct Node* root) {
    if (root == NULL) return;
    
    struct Queue* queue = createQueue(100);
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)) {
        int levelSize = queue->size;
        for (int i = 0; i < levelSize; i++) {
            struct Node* current = dequeue(queue);
            if (i == 0) {
                printf("%d ", current->data);
            }
            if (current->left) enqueue(queue, current->left);
            if (current->right) enqueue(queue, current->right);
        }
    }
    printf("\n");
    free(queue->array);
    free(queue);
}

int main() {
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    struct Node* root = createTree();
    printf("Left view of tree: ");
    leftView(root);
    return 0;
}
