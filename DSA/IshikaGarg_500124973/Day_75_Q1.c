#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// Create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Queue utility functions
int isEmpty(struct Queue* queue) { return (queue->size == 0); }

void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to print Left View
void leftView(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(100); // assuming max 100 nodes
    enqueue(q, root);

    while (!isEmpty(q)) {
        int n = q->size; // number of nodes at current level
        for (int i = 0; i < n; i++) {
            struct Node* node = dequeue(q);

            // First node at this level is part of left view
            if (i == 0) {
                printf("%d ", node->data);
            }

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);

    printf("Left View: ");
    leftView(root); // Output: 1 2 4

    return 0;
}
