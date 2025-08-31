#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Queue 
{
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};
struct Queue* createQueue(unsigned capacity) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}
int isEmpty(struct Queue* queue) 
{
    return (queue->size == 0);
}
int isFull(struct Queue* queue) 
{
    return (queue->size == queue->capacity);
}
void enqueue(struct Queue* queue, struct Node* item) 
{
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
struct Node* dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
void levelOrder(struct Node* root) 
{
    if (root == NULL) return;
    struct Queue* queue = createQueue(100); 
    enqueue(queue, root);
    while (!isEmpty(queue)) 
    {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }
}
int main() 
{
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    printf("Level Order Traversal: ");
    levelOrder(root);
    return 0;
}
