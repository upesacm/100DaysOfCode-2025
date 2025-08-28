#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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


int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->value + sumOfNodes(root->left) + sumOfNodes(root->right);
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

int isFull(struct Queue* queue) { return (queue->size == queue->capacity); }
int isEmpty(struct Queue* queue) { return (queue->size == 0); }

void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue)) return;
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


int findMax(struct Node* root) {
    if (root == NULL) return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->value;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}


int main() {
    
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    printf("Sum of nodes: %d\n", sumOfNodes(root1));             
    printf("Level order: "); levelOrderTraversal(root1);     
    printf("Max value: %d\n\n", findMax(root1));                  

  
    struct Node* root2 = newNode(10);
    root2->left = newNode(5);

    printf("Sum of nodes: %d\n", sumOfNodes(root2));            
    printf("Level order: "); levelOrderTraversal(root2);       
    printf("Max value: %d\n\n", findMax(root2));             

  
    struct Node* root3 = newNode(3);
    root3->left = newNode(2);
    root3->right = newNode(5);

    printf("Sum of nodes: %d\n", sumOfNodes(root3));              
    printf("Level order: "); levelOrderTraversal(root3);          
    printf("Max value: %d\n", findMax(root3));                  

    return 0;
}
