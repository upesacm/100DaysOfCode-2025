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

int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    // Example 1
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    printf("Sum of nodes: %d\n", sumOfNodes(root1)); // 6

    // Example 2
    struct Node* root2 = newNode(10);
    root2->left = newNode(5);
    printf("Sum of nodes: %d\n", sumOfNodes(root2)); // 15

    return 0;
}
