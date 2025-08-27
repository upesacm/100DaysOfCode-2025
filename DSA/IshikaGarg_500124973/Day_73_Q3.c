#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive max function
int findMax(struct Node* root) {
    if (root == NULL)
        return -1000000;  // assume very small value

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);

    printf("Maximum value in tree = %d\n", findMax(root));  // Output: 5
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive max function
int findMax(struct Node* root) {
    if (root == NULL)
        return -1000000;  // assume very small value

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);

    printf("Maximum value in tree = %d\n", findMax(root));  // Output: 5
    return 0;
}

