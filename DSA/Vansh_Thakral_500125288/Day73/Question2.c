#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}


struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}

int isEmpty(struct Queue* queue) { return (queue->size == 0); }

void enqueue(struct Queue* queue, struct Node* item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}


void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* node = dequeue(queue);
        printf("%d ", node->value);

        if (node->left) enqueue(queue, node->left);
        if (node->right) enqueue(queue, node->right);
    }
    printf("\n");
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Level order: ");
    levelOrderTraversal(root); 
    return 0;
}

