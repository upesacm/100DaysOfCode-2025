#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Simple queue for BFS
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    queue[++rear] = node;
    if (front == -1) front = 0;
}

struct Node* dequeue() {
    if (front == -1) return NULL;
    struct Node* temp = queue[front++];
    if (front > rear) front = rear = -1;
    return temp;
}

int isEmpty() {
    return front == -1;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left) enqueue(curr->left);
        if (curr->right) enqueue(curr->right);
    }
}

int main() {
    // Example 1
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    printf("Level order: ");
    levelOrder(root1); // 1 2 3
    printf("\n");

    // Example 2
    struct Node* root2 = newNode(10);
    root2->right = newNode(20);
    printf("Level order: ");
    levelOrder(root2); // 10 20
    printf("\n");

    return 0;
}
