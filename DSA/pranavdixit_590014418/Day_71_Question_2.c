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

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Example 1
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    printf("Leaf count: %d\n", countLeaves(root1));  // 2

    // Example 2
    struct Node* root2 = newNode(10);
    root2->right = newNode(20);
    root2->right->left = newNode(15);
    printf("Leaf count: %d\n", countLeaves(root2));  // 1

    return 0;
}
