#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal with counter to find Kth smallest
void findKthSmallest(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *result != -1) return;

    findKthSmallest(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    findKthSmallest(root->right, k, count, result);
}

int main() {
    // Tree:
    //       5
    //      / \
    //     3   6
    //    / \
    //   2   4
    //  /
    // 1
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->left->left->left = createNode(1);

    int k = 3;
    int count = 0;
    int result = -1;

    findKthSmallest(root, k, &count, &result);
    if (result != -1)
        printf("The %dth smallest element is: %d\n", k, result);  // Output: 3
    else
        printf("K is larger than the number of nodes.\n");

    return 0;
}
