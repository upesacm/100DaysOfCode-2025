#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to print Left View using level-order traversal
void leftView(struct Node* root) {
    if (root == NULL) return;

    // Queue for level-order traversal
    struct Node* queue[100];  
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            // First node of the level (leftmost)
            if (i == 0)
                printf("%d ", node->data);

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
}

// Driver code
int main() {
    /* Construct the following tree:
             1
            / \
           2   3
            \
             4
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);

    printf("Left View: ");
    leftView(root);  // Output: 1 2 4

    return 0;
}

