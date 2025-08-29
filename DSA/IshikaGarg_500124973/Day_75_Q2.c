#include <stdio.h>
#include <stdlib.h>

// Node definition
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

// Function to print Left View
void leftView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100]; // simple static queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            // First node at this level = leftmost
            if (i == 0)
                printf("%d ", node->data);

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
}

// Function to print Right View
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            // Last node at this level = rightmost
            if (i == size - 1)
                printf("%d ", node->data);

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
}

// Driver code
int main() {
    /* Example 1 (for Left View):
             1
            / \
           2   3
            \
             4
       Expected Left View: 1 2 4
    */
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->right = newNode(4);

    printf("Left View: ");
    leftView(root1);  // Output: 1 2 4

    printf("\n");

    /* Example 2 (for Right View):
             1
            / \
           2   3
          /
         4
       Expected Right View: 1 3 4
    */
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);

    printf("Right View: ");
    rightView(root2);  // Output: 1 3 4

    return 0;
}

